#include "AddressBook.h"
#include <iostream>

void AddressBook::add_contact(const std::string& name, const std::string& lastname, const std::string& address,const std::string& phone){
    AddressBook.push_back(new Contact(name,lastname,address,phone));
}

void AddressBook::remove_contact(const std::string& name, const std::string& lastname){
    if(AddressBook.size()<1){
        std::cout<<"Address book is empty";
    }
    else{
    std::vector<Contact*>::iterator it=AddressBook.begin();
    for(int i=0;i<AddressBook.size();++i){
        if(name==AddressBook[i]->get_name()&&lastname==AddressBook[i]->get_last_name()){
            AddressBook.erase(it);
            }
        else
        std::cout<<"No such contact"<<std::endl;

        ++it;
        }
    }
}

void AddressBook::show_address_book()const{
    for(auto& m:AddressBook){
        std::cout<<"ID: "<<m->get_id()<<std::endl;
        std::cout<<"Name: "<<m->get_name()<<std::endl;
        std::cout<<"Last Name: "<<m->get_last_name()<<std::endl;
        std::cout<<"Address: "<<m->get_address()<<std::endl;
        std::cout<<"Phone number: "<<m->get_phone_number()<<std::endl;
    }
}

AddressBook::~AddressBook(){
    for(auto& m:AddressBook){
        delete m;
    }
}