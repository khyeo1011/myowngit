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
    std::string read_data = decompressFile(file);
    size_t x = read_data.find('\0');
    size = std::stoi(data.substr(5, data.length() - x));
    data = read_data.substr(x+1);
}

void Blob::printData(){
    std::cout << data;
}