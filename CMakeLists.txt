
cmake_minimum_required(VERSION 4.0)

project(myowngit)

set(CMAKE_CXX_STANDARD 23) # Enable the C++23 standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})



add_subdirectory(lib)
add_subdirectory(src)
