#ifndef FORM
#define FORM

#include <fstream>
#include <iostream>
#include <string>
#include <iostream>
#include <bits/stdc++.h>

class Forms {
public:
    Forms() = default;
    ~Forms();
    void create_question(const std::string& filename);
    void create_form(const std::string& filename);
    void preview_form(const std::string& filename);
    void preview_questionaries();
    
private:
    std::ofstream form;
    std::ofstream db;
};

#endif // Form
