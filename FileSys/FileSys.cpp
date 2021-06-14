#include "FileSys.h"
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>


FileSys::FileSys():m_current{std::make_unique<Folder>()} {
    m_current -> set_name ("Root");
    path.push(m_current);
    path_name.push_back(m_current-> get_name());
}

void FileSys::mkdir(const std::string& item_name){
    if(item_name != "Root"){
        m_current->create(item_name);
    }
    else {
        std::cout<<"<Root> filename is reserved!\n";
    }
}

void FileSys::cd(const std::string& item_name){
    if(m_current->get_folder(item_name) == nullptr){
        std::cout<<item_name<<" is a file! Can not accsess.";
        std::cout<<std::endl;
    } 
    else {
        path.push(m_current);
        m_current = m_current->get_folder(item_name);
        path_name.push_back(m_current->get_name());
    } 
}

void FileSys::touch(const std::string& item_name){
    m_current->create_file(item_name);
}

void FileSys::cd(){
    if(m_current->get_name()!= "Root"){
        m_current = path.top();
        path.pop();
        path_name.erase(path_name.end());
    }
    else {
        std::cout<<"Can not move up!!\n";
    }
}

void FileSys::rm(const std::string& item_name){
    m_current -> remove(item_name);
}

void FileSys::ls(){
    m_current -> print_folder();
}

void FileSys::pwd() {
    for(auto& p_name: path_name){
        std::cout<<p_name<<" / ";
    }
    std::cout<<std::endl;
}

