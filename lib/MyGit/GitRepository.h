#ifndef _GIT_REPOSITORY_H
#define _GIT_REPOSITORY_H

#include <string>
#include "toml.hpp"
#include <iostream>
#include <exception>
#include <filesystem>
// A git repository only using the approach to worktree/.git
class GitRepository
{
private:
    std::filesystem::path worktree;
    std::filesystem::path gitdir;
    toml::table config;
public:
    GitRepository(std::string path = "", bool force = false);
    ~GitRepository();
};




#endif