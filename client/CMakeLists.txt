cmake_minimum_required(VERSION 3.23)
project(client)

set(CMAKE_CXX_STANDARD 20)

add_executable(client main.cpp ../classes/agency.cpp ../classes/agency.h ../classes/user.cpp ../classes/user.h ../classes/account.cpp ../classes/account.h ../classes/socket.h)