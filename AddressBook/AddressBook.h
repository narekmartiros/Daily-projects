#include <vector>
#include"Contact.h"
#include <string>

class AddressBook{
    public:
    void add_contact(const std::string& name, const std::string& lastname, const std::string& address,const std::string& phone);
    void remove_contact(const std::string& name, const std::string& lastname);
    void show_address_book()const;
    ~AddressBook();

    private:
    std::vector<Contact*> AddressBook;

};