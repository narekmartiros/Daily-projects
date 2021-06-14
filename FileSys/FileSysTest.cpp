#include "Terminal.h"
#include <string>
#include <bits/stdc++.h>


int main (){

    FileSys root;
    Terminal term;
    bool done=false;
    
    while(!done){
        std::cout<<"\n> ";
        std::string user_input;
        std::getline(std::cin, user_input);
       
        term.tokenize(user_input);
        if(term.is_valid_command(term.get_command())){
            if(term.get_command() == "mkdir"){
                root.mkdir(term.get_name());
            }
            else if(term.get_command() == "ls"){
                root.ls();
            }
            else if(term.get_command() == "rm"){
                root.rm(term.get_name());
            }
            else if(term.get_command() == "cd.."){
                root.cd();
            }
            else if(term.get_command() == "cd"){
                root.cd(term.get_name());
            }
            else if(term.get_command() == "touch"){
                root.touch(term.get_name());
            }
            else if(term.get_command() == "pwd"){
                root.pwd();
            }
            else if (term.get_command() == "exit"){
                done=true;
            } 
        term.clean_commands(); 
        }
    }    
}