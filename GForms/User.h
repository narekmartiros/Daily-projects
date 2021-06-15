#ifndef USER
#define USER

#include "Form.h"
#include <vector>

class User {
public:
    User() = default;
    void preview_questionaries();
    void preview_questionary(const std::string& filename);
    void take_quiz (const std::string& filename);

private:
    std::vector<std::string> m_answers;
    Forms m_form;
};

#endif // User
