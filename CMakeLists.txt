
cmake_minimum_required(VERSION 4.0)

set(CMAKE_CXX_STANDARD 23) # Enable the C++23 standard

project(myowngit)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.h)

find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)

add_executable(git ${SOURCE_FILES})

target_link_libraries(git PRIVATE OpenSSL::Crypto)
target_link_libraries(git PRIVATE ZLIB::ZLIB)

# Set the include directories for OpenSSL and ZLIB
target_include_directories(git PRIVATE ${OPENSSL_INCLUDE_DIR})
target_include_directories(git PRIVATE ${ZLIB_INCLUDE_DIR})