cmake_minimum_required(VERSION 3.23)
project(client)

set(CMAKE_CXX_STANDARD 20)

add_executable(client main.cpp ../classes/agency.cpp ../classes/agency.hpp ../classes/user.cpp ../classes/user.hpp ../classes/account.cpp ../classes/account.hpp ../classes/socket.hpp)