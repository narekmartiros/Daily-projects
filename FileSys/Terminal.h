#ifndef TERMINAL
#define TERMINAL

#include "FileSys.h"
#include <string>
#include <vector>


class Terminal {
public:
    bool is_valid_command(const std::string& command);
    void tokenize(const std::string& command);
    std::string& get_command();
    std::string get_name();
    void clean_commands();
private:
    std::vector<std::string> commands;
};

#endif // Terminal
