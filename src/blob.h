#ifndef _BLOB_H
#define _BLOB_H

#include "utils.h"
#include "gitobject.h"

class Blob : public GitObject
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
    std::string getData(); //Returns data stored in blob.
    size_t getSize();
};




#endif