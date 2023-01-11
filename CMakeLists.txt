cmake_minimum_required(VERSION 3.24)
project(cpp_sp2)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(include)
add_subdirectory(src)