#include "socket.hpp"

Server::Server() : m_ioservice(), m_acceptor(m_ioservice), m_connections() {}

json Server::read_directory(const std::string &directory_path, const std::string &account_id)
{
    DIR *dir;
    struct dirent *ent;
    static json output = {{"not", "found"}};
    if ((dir = opendir(directory_path.c_str())) == NULL)
    {
        std::cerr << "Impossible d'ouvrir le répertoire" << std::endl;
    }

    /* Répertoire ouvert avec succès */
    while ((ent = readdir(dir)) != NULL)
    {
        if (ent->d_type == DT_DIR)
        {
            /* C'est un répertoire, on le parcourt récursivement */
            std::string subdir_path = directory_path + "/" + std::string(ent->d_name);
            if (std::string(ent->d_name) != "." && std::string(ent->d_name) != "..")
            {
                read_directory(subdir_path, account_id);
            }
        }
        else
        {
            /* C'est un fichier, on lit son contenu */
            std::string file_path = directory_path + "/" + std::string(ent->d_name);
            std::ifstream file(file_path);
            if (file_path.find("A") == std::string::npos || !file.is_open())
                continue; // Si ce n'est pas un fichier de compte ou si on n'arrive pas à l'ouvrir

            json obj = json::parse(file);
            file.close();
            for (auto &it : obj["id"])
            {
                if (it["id"].dump() == account_id)
                {
                    output = it;
                    break;
                }
            }
        }
    }
    closedir(dir);
    return output;
}

void Server::createData(const std::string& agency_id, std::string& line, std::string& filename)
{
    if (!filesystem::exists("./data/" + agency_id + "/"))
        filesystem::create_directories("./data/" + agency_id + "/");

    filename = "data/" + agency_id + "/" + line + ".json";
    std::cout << "Création du fichier: " << filename << std::endl;
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

        if (line.find("{") == std::string::npos) // Si c'est pas du json
        {
            if (line.substr(0, 3) == "get") // Si on a besoin d'un compte qui n'appartient pas à l'agence décentralisée
            {
                std::string account_id = line.substr(4);
                std::cout << "Compte cherché: " << account_id << std::endl;

                auto account = read_directory("./data", account_id);
                std::cout << "Compte: " << account << std::endl;
                response = account;
            }
            else
            {
                agency_id = line.substr(1);
                createData(agency_id, line, filename);
            }
        }
        else
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