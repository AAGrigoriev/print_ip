cmake_minimum_required(VERSION 3.28)

project(print_ip LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(print_ip main.cpp)

add_subdirectory(print_ip)

target_link_libraries(print_ip INTERFACE helper)
