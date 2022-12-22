cmake_minimum_required(VERSION 3.24)
project(serveur_async)

set(CMAKE_CXX_STANDARD 20)
add_executable(serveur_async main.cpp ../classes/json.hpp)
