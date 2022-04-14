cmake_minimum_required(VERSION 3.20)
project(Graph)

set(CMAKE_CXX_STANDARD 17)
include_directories(/Users/fedor/CLionProjects/Lab_2)

add_executable(Graph main.cpp graph.hpp graph.h Node.h Node.hpp)
