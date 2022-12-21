cmake_minimum_required(VERSION 3.23)
project(N27)

set(CMAKE_CXX_STANDARD 20)

add_executable(N27 main.cpp classes/agency.cpp classes/agency.h classes/user.cpp classes/user.h classes/account.cpp classes/account.h)