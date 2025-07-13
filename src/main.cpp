#include <iostream>

int main(int argc, char *argv[])
{
    if (argc == 0)
    {
        std::cerr << "No command provided.\n";
        return EXIT_FAILURE;
    }

    std::string command = argv[1];
    if (command == "add")
    {
        // TODO:
    }
    else if (command == "cat-file")
    {
        // TODO:
    }
    else if (command == "check-ignore")
    {
        // TODO:
    }
    else if (command == "checkout")
    {
        // TODO:
    }
    else if (command == "commit")
    {
        // TODO:
    }
    else if (command == "hash-object")
    {
        // TODO:
    }
    else if (command == "init")
    {
        // TODO:
    }
    else if (command == "log")
    {
        // TODO:
    }
    else if (command == "ls-files")
    {
        // TODO:
    }
    else if (command == "ls-tree")
    {
        // TODO:
    }
    else if (command == "rev-parse")
    {
        // TODO:
    }
    else if (command == "rm")
    {
        // TODO:
    }
    else if (command == "show-ref")
    {
        // TODO:
    }
    else if (command == "status")
    {
        // TODO:
    }
    else if (command == "tag")
    {
        // TODO:
    }
    else
    {   
        std::cerr << "Bad command: " << command;
    }

    return 0;
}