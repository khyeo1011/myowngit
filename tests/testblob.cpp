#include <blob.h>
#include <gtest/gtest.h>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>


TEST(TestBlob, TestEmptyBlob){
    Blob b;
    ASSERT_EQ(0, b.getSize());
    ASSERT_EQ("", b.getData());
}





int main(int argc, char* argv[]) {
    return RUN_ALL_TESTS();
}