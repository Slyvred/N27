#pragma once
#include <boost/asio.hpp>
#include "json.hpp"
#include <iostream>

using json = nlohmann::json;

class Client
{
public:
  Client(const std::string &ip, const std::string &port)
      : ip_(ip), port_(port), socket_(io_context_) {}

  void Connect()
  {
    try
    {
      boost::asio::ip::tcp::resolver resolver(io_context_);
      boost::asio::ip::tcp::resolver::query query(ip_, port_);
      boost::asio::connect(socket_, resolver.resolve(query));
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << '\n';
    }
  }

  void SendRequest(const nlohmann::json &request)
  {
    try
    {
      std::string request_str = request.dump() + "\n";
      boost::asio::write(socket_, boost::asio::buffer(request_str));
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << '\n';
    }
  }

  void SendString(const std::string &str)
  {
    try
    {
      std::string request_str = str + "\n";
      boost::asio::write(socket_, boost::asio::buffer(request_str));
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << '\n';
    }
  }

  // Wrapper pour les fonctions du dessus
  void SendJSON(const std::string &filename, const json &request)
  {
    SendString(filename);
    SendRequest(request);
  }

  nlohmann::json GetResponse()
  {
    nlohmann::json response;
    try
    {
      boost::asio::streambuf buffer;
      boost::asio::read_until(socket_, buffer, "\n");
      std::istream stream(&buffer);
      std::string response_str;
      std::getline(stream, response_str);
      response = nlohmann::json::parse(response_str);
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << '\n';
    }
    return response;
  }

  void Close() { socket_.close(); }

private:
  std::string ip_;
  std::string port_;
  boost::asio::io_context io_context_;
  boost::asio::ip::tcp::socket socket_;
};
