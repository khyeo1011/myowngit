#include "command.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
    // Flush after every std::cout / std::cerr
    std::cout << std::unitbuf;
    std::cerr << std::unitbuf;

    

    return parseCommand(argc, argv);
}
