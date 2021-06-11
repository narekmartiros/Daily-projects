#include "AddressBook.h"
#include <iostream>

void print_address_book(const AddressBook& book);
void add_contact(AddressBook& book);
void rem_contact(AddressBook& book);
int display_menu();

int main(){
    AddressBook new_book;
    bool done = false;
    while(!done){
        int selection = display_menu();
        switch (selection) {
		case 0:
			done = true;
			break;
		case 1:
			add_contact(new_book);
			break;
		case 2:
			rem_contact(new_book);
			break;
		case 3:
			print_address_book(new_book);
			break;
		default:
			std::cerr << "Unknown command." << std::endl;
			break;
		}
    }
}

void print_address_book( const AddressBook& book){
    std::cout<<std::endl;
    book.show_address_book();
    std::cout<<std::endl;
}

void add_contact(AddressBook& book){
    std::string name;
    std::cout<<"Add name"<<std::endl;
    std::cin>>name;
    std::cin.get();

    std::string lastname;
    std::cout<<"Add last name"<<std::endl;
    std::cin>>lastname;
    std::cin.get();

    std::string address;
    std::cout<<"Add address"<<std::endl;
    std::getline(std::cin,address);

    std::string phone;
    std::cout<<"Add phone number"<<std::endl;
    std::cin>>phone;

    book.add_contact(name,lastname,address,phone);
}

void rem_contact(AddressBook& book){
    std::string name;
    std::cout<<"Name?"<<std::endl;
    std::cin>>name;

    std::string lastname;
    std::cout<<"Last name?"<<std::endl;
    std::cin>>lastname;
    book.remove_contact(name,lastname);
}

int display_menu() {
	int selection;
	std::cout << std::endl;
    std::cout <<"The most simple address book"<<std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "1) Create contact" << std::endl;
	std::cout << "2) Remove contact" << std::endl;
	std::cout << "3) Show address book" << std::endl;
    std::cout << "0) Quit" << std::endl;
	std::cout << "---> ";
	std::cin >> selection;
	return selection;
}
