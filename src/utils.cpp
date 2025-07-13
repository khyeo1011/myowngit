#include "utils.h"

std::string decompressFile(std::string &file)
{
    // Read file;
    std::fstream input(file, std::ios::binary);
    if (!input.is_open())
    {
        throw std::ios_base::failure("Could not open file : " + file);
    }
    input.seekg(0, std::ios::end);
    size_t input_size = input.tellg();
    input.seekg(0, std::ios::beg);
    std::vector<unsigned char> compressed_data(input_size);
    input.read(reinterpret_cast<char *>(compressed_data.data()), input_size);
    input.close();

    z_stream stream;
    stream.zalloc = Z_NULL;
    stream.zfree = Z_NULL;
    stream.opaque = Z_NULL;
    stream.avail_in = compressed_data.size();
    stream.next_in = compressed_data.data();
    int ret = inflateInit(&stream);

    if (ret != Z_OK)
    {
        throw std::runtime_error("inflateInit failed: " + std::to_string(ret));
    }

    std::vector<char> decompressedData;
    char buffer[4096];

    do
    {
        stream.avail_out = sizeof(buffer);
        stream.next_out = reinterpret_cast<Bytef *>(buffer);
        ret = inflate(&stream, Z_NO_FLUSH);

        if (ret != Z_OK)
        {
            std::cerr << "Error during zlib inflate: " << ret << std::endl;
            inflateEnd(&stream);
            abort();
        }

        decompressedData.insert(decompressedData.end(), buffer, buffer + (sizeof(buffer) - stream.avail_out));
    } while (ret == Z_OK);

    inflateEnd(&stream);

    std::string read_data(decompressedData.begin(), decompressedData.end());
    size_t x = read_data.find('\0');
    if (x == read_data.length() || x == 5)
    {
        std::cerr << "not a git file" << std::endl;
        abort();
    }
    return read_data;
}