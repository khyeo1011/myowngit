#ifndef _BLOB_H
#define _BLOB_H

#include "utils.h"

class Blob
{
private:
    /* data */
    size_t size; // Size of the blob (in bytes)
    std::string data; // Data of the blob

public:
    Blob(); // creates empty blob
    Blob(std::string& file); //Creates blob based on file.
    ~Blob();
    void printData(); //Prints data of the blob.
};




#endif