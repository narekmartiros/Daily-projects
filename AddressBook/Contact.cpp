#include "Contact.h"
#include <string>

int Contact::ID=1;

Contact::Contact(): m_name{"John"},m_last_name{"Smith"},m_address{"New York"}, m_phone_number{"374 29 1107"},m_id{++ID}{}
Contact::Contact(const std::string& name, const std::string& lastname, const std::string& address,const std::string& phone)
    :m_id{++ID}
    ,m_name{name}
    ,m_last_name{lastname}
    ,m_address{address}
    ,m_phone_number{phone}{}


Contact::~Contact(){}

void Contact::set_name(const std::string& name){
    m_name=name;
}
void Contact::set_last_name(const std::string& name){
    m_last_name=name;
}
void Contact::set_address(const std::string& address){
    m_address=address;
}
void Contact::set_phone_number(const std::string& number){
    m_phone_number=number;
}

std::string Contact::get_name()const{
    return m_name;
}
std::string Contact::get_last_name()const{
    return m_last_name;
}
std::string Contact::get_address()const{
    return m_address;
}
std::string Contact::get_phone_number()const{
    return m_phone_number;
}
int Contact::get_id()const{
    return m_id;
}