#include "socket.hpp"
#include <algorithm>
#include <chrono>
#include <string>

Server::Server() : m_ioservice(), m_acceptor(m_ioservice), m_connections() {}

json Server::read_directory(const std::string &directory_path, const std::string &account_id)
{
    static json output = {{"key", "value"}};
    std::filesystem::path dir_path(directory_path);

    if (!std::filesystem::is_directory(dir_path))
    {
        std::cerr << "Impossible d'ouvrir le répertoire" << std::endl;
        return output;
    }

    if (std::filesystem::is_empty(dir_path))
    {
        std::cerr << "Répertoire vide" << std::endl;
        return output;
    }

    for (const auto &entry : std::filesystem::recursive_directory_iterator(dir_path))
    {
        if (!entry.is_regular_file())
            continue;

        std::string file_path = entry.path().string();
        std::string filename = entry.path().filename().string();
        filename = filename.substr(0, filename.length() - 5); // .json

        if (file_path.find("A") == std::string::npos)
            continue; // Si ce n'est pas un fichier de compte

        std::ifstream file(file_path);
        if (!file.is_open())
            continue; // Si on n'arrive pas à ouvrir le fichier

        json obj = json::parse(file);
        file.close();
        output = {{"file", filename}};
        for (auto &it : obj["id"])
        {
            if (it["id"].dump() == account_id)
            {
                output["acc"] = obj;
                return output;
            }
        }
    }
    return output;
}

void Server::createData(const std::string& agency_id, std::string& line, std::string& filename)
{
    if (!filesystem::exists("./data/" + agency_id + "/"))
        filesystem::create_directories("./data/" + agency_id + "/");

    filename = "data/" + agency_id + "/" + line + ".json";

    std::cout << "Création du fichier: " << filename << std::endl;
}

void Server::update(const std::string& agency_id, const std::string& last_write_time)
{
    static json output = {{"key", "value"}};
    std::filesystem::path dir_path("./data/" + agency_id);

    auto count = std::stol(last_write_time);

    if (!std::filesystem::is_directory(dir_path))
    {
        std::cerr << "Impossible d'ouvrir le répertoire" << std::endl;
        return;
    }

    if (std::filesystem::is_empty(dir_path))
    {
        std::cerr << "Répertoire vide" << std::endl;
        return;
    }

    for (const auto &entry : std::filesystem::recursive_directory_iterator(dir_path))
    {
        if (!entry.is_regular_file())
            continue;

        if (abs(entry.last_write_time().time_since_epoch().count()) > count) // Si notre db est plus vielle
            continue;

        ifstream file(entry.path().string());
        if (!file.is_open())
            continue;

        response = json::parse(file);
        file.close();

        std::cout << "Envoi de " << entry.path().filename().string() << std::endl;
    }
}

std::vector<std::string> split(const std::string &str, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream token_stream(str);
    while (std::getline(token_stream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

void Server::handle_command(std::string &line, std::string &agency_id, std::string &filename)
{
    if (line.find("{") == std::string::npos) // Si on reçoit une commande
    {
        std::cout << "command: " << line << std::endl;
        auto command = split(line, ' ');

        if (command[0] == "get" && command.size() == 2) // Si on a besoin d'un compte qui n'appartient pas à l'agence décentralisée
        {
            std::string account_id = command[1];
            std::cout << "Compte cherché: " << account_id << std::endl;

            auto account = read_directory("./data", account_id);
            std::cout << "Compte: " << account["acc"]["id"][account_id] << std::endl;
            response = account;
        }
        else if (command[0] == "update" && command.size() == 3)
        {
            update(command[1], command[2]);
        }
        else
        {
            agency_id = line.substr(1);
            createData(agency_id, line, filename);
        }
    }
    else // Si on reçoit du json
    {
        json obj = json::parse(line);
        std::ofstream file(filename);
        if (file.is_open())
        {
            file << setw(2) << obj << std::endl;
            file.close();
        }
        std::cout << "Fichier reçu" /*<< obj.dump()*/ << std::endl;
    }
}

void Server::handle_read(con_handle_t con_handle, boost::system::error_code const &err, size_t bytes_transfered)
{
    if (bytes_transfered > 0)
    {
        std::istream is(&con_handle->read_buffer);
        std::string line;
        static std::string filename;
        static std::string agency_id;
        std::getline(is, line);

       handle_command(line, agency_id, filename);
    }

    if (!err)
    {
        do_async_read(con_handle);
    }
    else
    {
        std::cerr << "Erreur: " << err.message() << std::endl;
        m_connections.erase(con_handle);
    }
}

void Server::do_async_read(con_handle_t con_handle)
{
    auto handler = boost::bind(&Server::handle_read, this, con_handle, boost::asio::placeholders::error,
                               boost::asio::placeholders::bytes_transferred);
    boost::asio::async_read_until(con_handle->socket, con_handle->read_buffer, "\n", handler);
}

void Server::handle_write(con_handle_t con_handle, std::shared_ptr<std::string> msg_buffer,
                          boost::system::error_code const &err)
{
    if (!err)
    {
        std::cout << "Envoi du message terminé\n";
        /*if (con_handle->socket.is_open())
        {
          // Write completed successfully and connection is open
        }*/
    }
    else
    {
        std::cerr << "Erreur: " << err.message() << std::endl;
        m_connections.erase(con_handle);
    }
}

void Server::handle_accept(con_handle_t con_handle, boost::system::error_code const &err)
{
    if (!err)
    {
        // std::cout << "Connection from: " << con_handle->socket().remote_endpoint().address().to_string() << "\n";
        std::cout << "Envoi du message\n";
        json msg = {{"key", "value"}};

        auto buff = std::make_shared<std::string>(((response.is_null()) ? msg.dump() : response.dump()) + "\n");
        auto handler = boost::bind(&Server::handle_write, this, con_handle, buff, boost::asio::placeholders::error);
        boost::asio::async_write(con_handle->socket, boost::asio::buffer(*buff), handler);
        do_async_read(con_handle);
    }
    else
    {
        std::cerr << "Erreur: " << err.message() << std::endl;
        m_connections.erase(con_handle);
    }
    start_accept();
}

void Server::start_accept()
{
    auto con_handle = m_connections.emplace(m_connections.begin(), m_ioservice);
    auto handler = boost::bind(&Server::handle_accept, this, con_handle, boost::asio::placeholders::error);
    m_acceptor.async_accept(con_handle->socket, handler);
}

void Server::listen(uint16_t port)
{
    auto endpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port);
    m_acceptor.open(endpoint.protocol());
    m_acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
    m_acceptor.bind(endpoint);
    m_acceptor.listen();
    start_accept();
    std::cout << "Serveur en écoute sur le port " << port << std::endl;
}

void Server::run()
{
    m_ioservice.run();
}