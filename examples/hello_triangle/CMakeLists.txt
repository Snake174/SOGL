cmake_minimum_required(VERSION 3.0.2)
project(hello_triangle)

add_executable(hello_triangle main.cpp)
target_link_libraries(hello_triangle SOGL)
