

find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB_RECURSE SOURCE_FILES "${SOURCE_DIR}/*.cpp" "${SOURCE_DIR}/*.h")

add_executable(git ${SOURCE_FILES})
add_library(gitlib STATIC ${SOURCE_FILES})

target_link_libraries(git PRIVATE OpenSSL::Crypto)
target_link_libraries(git PRIVATE ZLIB::ZLIB)
target_link_libraries(gitlib STATIC OpenSSL::Crypto)
target_link_libraries(gitlib STATIC ZLIB::ZLIB)

# Set the include directories for OpenSSL and ZLIB
target_include_directories(git PRIVATE ${OPENSSL_INCLUDE_DIR})
target_include_directories(git PRIVATE ${ZLIB_INCLUDE_DIR})
target_include_directories(gitlib PUBLIC ${OPENSSL_INCLUDE_DIR})
target_include_directories(gitlib PUBLIC ${ZLIB_INCLUDE_DIR})
target_include_directories(gitlib PUBLIC ${SOURCE_DIR})