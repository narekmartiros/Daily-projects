#include <string> 

class Contact{
    public:
    Contact();
    Contact(const std::string& name, const std::string& lastname, const std::string& address,const std::string& phone);
    ~Contact();
    std::string get_name()const;
    std::string get_last_name()const;
    std::string get_address()const;
    std::string get_phone_number()const;
    void set_name(const std::string& name);
    void set_last_name(const std::string& name);
    void set_address(const std::string& name);
    void set_phone_number(const std::string& name);
    int get_id()const;
    
    private:
    std::string m_name;
    std::string m_last_name;
    std::string m_address;
    std::string m_phone_number;
    static int ID;
    int m_id;
};