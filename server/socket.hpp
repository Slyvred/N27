#pragma once
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <iomanip>
#include <list>
#include <fstream>
#include <filesystem>
#include <dirent.h>
#include "../classes/json.hpp"

using json = nlohmann::json;
using namespace std;

/*class Server {
 public:
  Server(const std::string &port) : port_(port), acceptor_(io_context_) {
    boost::asio::ip::tcp::resolver resolver(io_context_);
    boost::asio::ip::tcp::resolver::query query(boost::asio::ip::tcp::v4(), port_);
    boost::asio::ip::tcp::endpoint endpoint = *resolver.resolve(query).begin();
    acceptor_.open(endpoint.protocol());
    acceptor_.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
    acceptor_.bind(endpoint);
    acceptor_.listen();
  }

  void Accept() {
    acceptor_.async_accept(
        [this](const boost::system::error_code &error,
               boost::asio::ip::tcp::socket socket) {
          if (!error) {
            std::make_shared<Session>(std::move(socket))->Start();
            std::cout << "Agency connected" << std::endl;
          }

          Accept();
        });
  }

  void Run() { io_context_.run(); }

 private:
  class Session : public std::enable_shared_from_this<Session> {
   public:
    Session(boost::asio::ip::tcp::socket socket) : socket_(std::move(socket)) {}

    void Start() { Read(); }

   private:
    void Read() {
      boost::asio::async_read(
          socket_, boost::asio::dynamic_buffer(data_),
          [this](          boost::system::error_code error, size_t bytes_transferred) {
            if (!error) {
              nlohmann::json request = nlohmann::json::parse(data_);
              std::cout << "Received request: " << request.dump() << std::endl;

              nlohmann::json response = {{"key", "value"}};
              std::string response_str = response.dump() + "\n";
              boost::asio::write(socket_, boost::asio::buffer(response_str));

            }
          });
    }

    boost::asio::ip::tcp::socket socket_;
    std::string data_;
  };

  std::string port_;
  boost::asio::io_context io_context_;
  boost::asio::ip::tcp::acceptor acceptor_;
};*/

struct Connection
{
  boost::asio::ip::tcp::socket socket;
  boost::asio::streambuf read_buffer;

  Connection(boost::asio::io_service &io_service) : socket(io_service), read_buffer() {}

  Connection(boost::asio::io_service &io_service, size_t max_buffer_size) : socket(io_service),
                                                                            read_buffer(max_buffer_size) {}
};

class Server
{
  boost::asio::io_service m_ioservice;
  boost::asio::ip::tcp::acceptor m_acceptor;
  std::list<Connection> m_connections;
  using con_handle_t = std::list<Connection>::iterator;

private:
  static std::string file;

public:
  Server() : m_ioservice(), m_acceptor(m_ioservice), m_connections() {}

  void handle_read(con_handle_t con_handle, boost::system::error_code const &err, size_t bytes_transfered)
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
          DIR *dir;
          struct dirent *ent;
          if ((dir = opendir("./data")) != NULL)
          {
            /* Répertoire ouvert avec succès */
            while ((ent = readdir(dir)) != NULL)
            {
              std::cout << ent->d_name << std::endl;
            }
            closedir(dir);
          }
          else
          {
            /* Impossible d'ouvrir le répertoire */
            perror("");
          }
        }

        agency_id = line.substr(1);
        if (!filesystem::exists("./data/" + agency_id + "/"))
          filesystem::create_directories("./data/" + agency_id + "/");

        filename = "data/" + agency_id + "/" + line + ".json";
        std::cout << "Création du fichier: " << filename << std::endl;
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
        std::cout << "Message reçu: " << obj.dump() << std::endl;
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

  void do_async_read(con_handle_t con_handle)
  {
    auto handler = boost::bind(&Server::handle_read, this, con_handle, boost::asio::placeholders::error,
                               boost::asio::placeholders::bytes_transferred);
    boost::asio::async_read_until(con_handle->socket, con_handle->read_buffer, "\n", handler);
  }

  void handle_write(con_handle_t con_handle, std::shared_ptr<std::string> msg_buffer,
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

  void handle_accept(con_handle_t con_handle, boost::system::error_code const &err)
  {
    if (!err)
    {
      //std::cout << "Connection from: " << con_handle->socket().remote_endpoint().address().to_string() << "\n";
      std::cout << "Envoi du message\n";
      json msg = {{"key", "value"}};

      auto buff = std::make_shared<std::string>(msg.dump() + "\n");
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

  void start_accept()
  {
    auto con_handle = m_connections.emplace(m_connections.begin(), m_ioservice);
    auto handler = boost::bind(&Server::handle_accept, this, con_handle, boost::asio::placeholders::error);
    m_acceptor.async_accept(con_handle->socket, handler);
  }

  void listen(uint16_t port)
  {
    auto endpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port);
    m_acceptor.open(endpoint.protocol());
    m_acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
    m_acceptor.bind(endpoint);
    m_acceptor.listen();
    start_accept();
    std::cout << "Serveur en écoute sur le port " << port << std::endl;
  }

  void run()
  {
    m_ioservice.run();
  }
};