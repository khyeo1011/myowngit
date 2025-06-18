include(FetchContent)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB_RECURSE SOURCE_FILES "${SOURCE_DIR}/*.cpp" "${SOURCE_DIR}/*.h")

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

FetchContent_MakeAvailable(googletest)
enable_testing()

add_library(GTest::GTest INTERFACE IMPORTED)
add_library(gitlib::gitlib INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest gtest_main)

add_executable(testblob ${SOURCE_DIR}/testblob.cpp)

target_link_libraries(testblob PRIVATE GTest::GTest gitlib)

add_test(NAME testblob COMMAND testblob)