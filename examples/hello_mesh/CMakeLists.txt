cmake_minimum_required(VERSION 3.0.2)
project(instanced_rendering)

add_executable(instanced_rendering main.cpp)
target_link_libraries(instanced_rendering SOGL)
