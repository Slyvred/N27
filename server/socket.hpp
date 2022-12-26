#pragma once
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <iomanip>
#include <list>
#include <fstream>
#include <filesystem>
// #include <dirent.h>
#include "../classes/json.hpp"

using json = nlohmann::json;
using namespace std;

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
  json response;

public:
  Server();

  json read_directory(const std::string &directory_path, const std::string &account_id);
  void createData(const std::string& agency_id, std::string& line, std::string& filename);

  void handle_read(con_handle_t con_handle, boost::system::error_code const &err, size_t bytes_transfered);
  void do_async_read(con_handle_t con_handle);
  void handle_write(con_handle_t con_handle, std::shared_ptr<std::string> msg_buffer, boost::system::error_code const &err);
  void handle_accept(con_handle_t con_handle, boost::system::error_code const &err);
  void start_accept();
  void listen(uint16_t port);
  void run();
};