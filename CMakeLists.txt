cmake_minimum_required(VERSION 3.30)
project(cleandir)
set(HOME_DIR "$ENV{HOME}")
add_definitions(-DROOT_DIR="${HOME_DIR}")

set(CMAKE_CXX_STANDARD 20)

add_executable(cleandir src/main.cpp
        src/parser.hpp
        src/runner.hpp)
