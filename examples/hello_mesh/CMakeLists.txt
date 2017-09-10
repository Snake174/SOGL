cmake_minimum_required(VERSION 3.0.2)
project(hello_mesh)

add_executable(hello_mesh main.cpp)
target_link_libraries(hello_mesh SOGL)
