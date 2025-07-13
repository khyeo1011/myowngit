#include "blob.h"

Blob::Blob()
{
    size = 0;
}

Blob::~Blob()
{
}

Blob::Blob(std::string &file)
{
    try {
        std::string read_data = decompressFile(file);
        size_t x = read_data.find('\0');
        size = std::stoi(read_data.substr(5, x - 5));
        data = read_data.substr(x + 1);
    } catch (const std::exception& e) {
        std::cerr << "Error creating blob from file: " << e.what() << std::endl;
        size = 0;
        data = "";
    }
}

void Blob::printData()
{
    std::cout << data;
}

std::string Blob::getData()
{
    return data;
}

size_t Blob::getSize()
{
    return size;
}