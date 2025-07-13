#include <blob.h>
#include <gtest/gtest.h>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <zlib.h>


void create_test_blob_file(const std::string& filepath, const std::string& content) {
    std::string header = "blob " + std::to_string(content.size()) + '\0';
    std::string data_to_compress = header + content;

    z_stream stream;
    stream.zalloc = Z_NULL;
    stream.zfree = Z_NULL;
    stream.opaque = Z_NULL;
    
    if (deflateInit(&stream, Z_DEFAULT_COMPRESSION) != Z_OK) {
        throw std::runtime_error("deflateInit failed");
    }

    stream.avail_in = data_to_compress.size();
    stream.next_in = (Bytef*)data_to_compress.data();

    std::vector<char> compressed_data(deflateBound(&stream, data_to_compress.size()));
    stream.avail_out = compressed_data.size();
    stream.next_out = (Bytef*)compressed_data.data();

    
    compressed_data.resize(stream.total_out);

    std::ofstream outfile(filepath, std::ios::binary);
    if (!outfile) {
        throw std::runtime_error("Could not open file for writing: " + filepath);
    }
    outfile.write(compressed_data.data(), compressed_data.size());
}


TEST(TestBlob, TestEmptyBlob){
    Blob b;
    ASSERT_EQ(0, b.getSize());
    ASSERT_EQ("", b.getData());
}

TEST(TestBlob, TestBlobFromFile){
    std::string test_content = "hello world";
    std::string test_file = "test_blob.zlib";

    try {
        create_test_blob_file(test_file, test_content);
        
        Blob b(test_file);
        ASSERT_EQ(test_content.size(), b.getSize());
        ASSERT_EQ(test_content, b.getData());

    } catch (const std::exception& e) {
        // This will now catch the error and display a useful message
        FAIL() << "TestBlobFromFile failed with exception: " << e.what();
    }

    // Clean up the dummy file
    std::filesystem::remove(test_file);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
