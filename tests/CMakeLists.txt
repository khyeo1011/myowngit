
enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

FetchContent_MakeAvailable(googletest)


add_executable(testblob testblob.cpp)


target_link_libraries(testblob PRIVATE gitlib gtest_main)


include(GoogleTest)

gtest_discover_tests(testblob WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
gtest_discover_tests(testblob)