#ifndef ADMIN
#define ADMIN
#include "User.h"

class Admin {
public:
    Admin() = default;
    void create_quiz(const std::string& filename);
    void preview_quiz(const std::string& filename);
    void preview_quizs();

private:
    Forms m_form;
};

#endif // Admin