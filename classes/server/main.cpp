#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <fstream>
#include <cstdint>
#include <iostream>
#include <list>
#include <memory>

struct Connection {
    boost::asio::ip::tcp::socket socket;
    boost::asio::streambuf read_buffer;

    Connection(boost::asio::io_service &io_service) : socket(io_service), read_buffer() {}

    Connection(boost::asio::io_service &io_service, size_t max_buffer_size) : socket(io_service),
                                                                              read_buffer(max_buffer_size) {}
};

class Server {
    boost::asio::io_service m_ioservice;
    boost::asio::ip::tcp::acceptor m_acceptor;
    std::list<Connection> m_connections;
    using con_handle_t = std::list<Connection>::iterator;

public:

    Server() : m_ioservice(), m_acceptor(m_ioservice), m_connections() {}

    void handle_read(con_handle_t con_handle, boost::system::error_code const &err, size_t bytes_transfered) {
        if (bytes_transfered > 0) {
            std::istream is(&con_handle->read_buffer);
            std::string line;

           std::ofstream file("T1804289383.json", std::ios_base::app);
           std::getline(is, line);
           file << line;
           file.close();
        

            std::cout << "Message reçu: " << line << std::endl;
        }

        if (!err) {
            do_async_read(con_handle);
        } else {
            std::cerr << "Erreur: " << err.message() << std::endl;
            m_connections.erase(con_handle);
        }
    }

    void do_async_read(con_handle_t con_handle) {
        auto handler = boost::bind(&Server::handle_read, this, con_handle, boost::asio::placeholders::error,
                                   boost::asio::placeholders::bytes_transferred);
        boost::asio::async_read_until(con_handle->socket, con_handle->read_buffer, "\n", handler);
    }

    void handle_write(con_handle_t con_handle, std::shared_ptr<std::string> msg_buffer,
                      boost::system::error_code const &err) {
        if (!err) {
            std::cout << "Envoi du message terminé\n";
            if (con_handle->socket.is_open()) {
                // Write completed successfully and connection is open
            }
        } else {
            std::cerr << "Erreur: " << err.message() << std::endl;
            m_connections.erase(con_handle);
        }
    }

    void handle_accept(con_handle_t con_handle, boost::system::error_code const &err) {
        if (!err) {
            //std::cout << "Connection from: " << con_handle->remote_endpoint().address().to_string() << "\n";
            std::cout << "Envoi du message\n";
            auto buff = std::make_shared<std::string>("Client connecté!\r\n\r\n");
            auto handler = boost::bind(&Server::handle_write, this, con_handle, buff, boost::asio::placeholders::error);
            boost::asio::async_write(con_handle->socket, boost::asio::buffer(*buff), handler);
            do_async_read(con_handle);
        } else {
            std::cerr << "Erreur: " << err.message() << std::endl;
            m_connections.erase(con_handle);
        }
        start_accept();
    }

    void start_accept() {
        auto con_handle = m_connections.emplace(m_connections.begin(), m_ioservice);
        auto handler = boost::bind(&Server::handle_accept, this, con_handle, boost::asio::placeholders::error);
        m_acceptor.async_accept(con_handle->socket, handler);
    }

    void listen(uint16_t port) {
        auto endpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port);
        m_acceptor.open(endpoint.protocol());
        m_acceptor.set_option(boost::asio::ip::tcp::acceptor::reuse_address(true));
        m_acceptor.bind(endpoint);
        m_acceptor.listen();
        start_accept();
    }

    void run() {
        m_ioservice.run();
    }
};

int main(int, char **) 
{
    auto srv = Server();
    srv.listen(1234);

    srv.run();
    return 0;
}