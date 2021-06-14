#include "Folder.h"
#include <iostream>

Folder::Folder(){};

void Folder::create(const std::string& name){
    m_folder.emplace(name, std::make_unique<Folder>());
    m_folder[name]->m_parent_folder=m_parent_folder;
    m_folder[name]->m_folder_name=name;

}

void Folder::create_file(const std::string filename){
  
    m_folder.emplace(filename, nullptr);
   // m_folder[filename]->m_parent_folder=m_parent_folder;
   // m_folder[filename]->m_folder_name=filename;
   
}

std::shared_ptr<Folder> Folder::get_folder(const std::string& name){
    for(auto& x: m_folder){
        if(x.first==name){
            return m_folder[name];

        }
        
    }
    return nullptr;
    
}


void Folder::remove(const std::string& name){
      m_folder.erase(name);
}

void Folder::print_folder()const{
    std::cout<<std::endl;
    std::cout<<"Current folder: "<< m_folder_name<<std::endl;
    for(auto& folder: m_folder){
        std::cout<<folder.first<<"  ";
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
}

void Folder::set_name(const std::string& name){
    m_folder_name=name;
}

const std::string& Folder::get_name()const{
    return m_folder_name;
}