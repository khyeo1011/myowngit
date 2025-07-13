#include "GitRepository.h"

GitRepository::GitRepository(std::string path = "", bool force = false){
    worktree = path;
    gitdir = path + "/.git";
    if(!(force || std::filesystem::exists(gitdir)))
        throw std::runtime_error("Not a Git Repository!" + path);

    try
    {
        config =  toml::parse_file(path + "/.git/config");
    }
    catch(const toml::parse_error& err)
    {
        throw err;
    }
    
    if(!force){
        int version = (int)config["core"]["repositoryformatversion"].as_integer();
        if(version != 0){
            throw std::runtime_error("Unsupported repo format version");
        }
    }
    
}