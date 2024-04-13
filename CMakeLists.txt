cmake_minimum_required(VERSION 3.28)

project(project VERSION 0.0.$ENV{GITHUB_RUN_NUMBER})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(project main.cpp)

add_subdirectory(helper)
add_subdirectory(test)

link_libraries(INTERFACE helper)

enable_testing()
