#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <fstream>

using namespace boost::asio;
using ip::tcp;
using std::cout;
using std::endl;
using std::string;

void handle_write(const boost::system::error_code &error, size_t bytes_transferred)
{
    if (error)
    {
        std::cerr << "Erreur lors de l'envoi du fichier";
    }
}

void send_file(tcp::socket& sock, const std::string& file_name)
{
    std::ifstream file(file_name, std::ios::in | std::ios::binary);

    // Vérifiez que le fichier a pu être ouvert
    if (!file.is_open())
    {
        throw std::runtime_error("Impossible d'ouvrir le fichier: " + file_name);
    }

    // Envoyez le fichier par morceaux en utilisant async_write_some
    char data[1024];
    while (file.read(data, 1024))
    {
        sock.async_write_some(
            boost::asio::buffer(data, 1024),
            boost::bind(&handle_write,
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));
    }

    // Envoyez le reste du fichier (si la taille du fichier n'est pas un multiple de 1024)
    sock.async_write_some(
        boost::asio::buffer(data, file.gcount()),
        boost::bind(&handle_write,
                    boost::asio::placeholders::error,
                    boost::asio::placeholders::bytes_transferred));

    file.close();
}

int main()
{
    boost::asio::io_service io_service;
    // socket creation
    tcp::socket socket(io_service);
    // connection
    socket.connect(tcp::endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 1234));
    // request/message from client
    //const string msg = "T1804289383\n";
    boost::system::error_code error;
    //boost::asio::write(socket, boost::asio::buffer(msg), error);
    send_file(socket, "../T1804289383.json");
    if (!error)
    {
        cout << "Le message a été envoyé !" << endl;
    }
    else
    {
        cout << "Echec de l'envoi: " << error.message() << endl;
    }
    // getting response from server
    boost::asio::streambuf receive_buffer;
    boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
    if (error && error != boost::asio::error::eof)
    {
        cout << "Echec de la réception: " << error.message() << endl;
    }
    else
    {
        const char *data = boost::asio::buffer_cast<const char *>(receive_buffer.data());
        cout << data << endl;
    }
    return 0;
}