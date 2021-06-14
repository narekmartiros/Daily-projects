#ifndef FILESYS
#define FILESYS

#include "Folder.h"
#include <memory>
#include <stack>
#include <vector>

class FileSys {
public:
    FileSys();
    void mkdir(const std::string& item_name);
    void pwd();
    void cd(const std::string& item_name);
    void cd();
    void touch(const std::string& item_name);
    void rm(const std::string& item_name);
    void ls();

private:
    std::shared_ptr<Folder> m_current;
    std::stack <std::shared_ptr<Folder> > path;
    std::vector<std::string> path_name;
};

#endif // Filesys