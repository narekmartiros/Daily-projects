
#include "Terminal.h"
#include <map>
#include <vector>
#include <bits/stdc++.h>

void Terminal::tokenize(const std::string& command){
    std::istringstream ss(command);
    std::string m;
	while(ss>>m){
        std::string s = m;
		commands.push_back(s);
	}
}

void Terminal::clean_commands() {
    commands.clear();
}

bool Terminal::is_valid_command (const std::string& command) {
    if(command == "mkdir"||command == "ls"||command == "pwd"||command == "cd"||command == "touch"||command == "rm"||command == "cd.."||command == "exit"){
        if(commands.size()<=2){
            return true;
        }
    } 
    else {
        std::cout<<"Unknown commandn\n";
    }
    return false;
}

std::string& Terminal::get_command() {
    return commands[0];
}
std::string Terminal::get_name() {
    if(commands.size()>1){
        return commands[1];
    } 
    std::string warning="no such folder or filename!!!\n";
    return warning;
}