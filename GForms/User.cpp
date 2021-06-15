#include "User.h"

void User::preview_questionary(const std::string& filename) {
    m_form.preview_form(filename);
}

void User::preview_questionaries(){
    m_form.preview_questionaries();
}

void User::take_quiz (const std::string& filename) {
    std::ifstream dbs("Forms_DB");
    std::string form_name;
    int even = 0;
    while(!dbs.eof()) {
        std::string temp;
        std::string answers;
        std::string ans;
        std::getline(dbs, temp);
        if(even == 0 || even%2 == 0){
            if(temp == filename){
                form_name = temp;
                std::getline(dbs, answers);
                std::istringstream ss(answers);
                while(ss >> ans){
                    std::string s = ans;
                    m_answers.push_back(s);
                }
                break;
            }
        }
        ++even;
    }
    dbs.close();

    preview_questionary(form_name);
    int count = 0;
    for(int i = 0; i < m_answers.size(); ++i){
        std::string given_answer;
        std::cout << "Question "<<i+1<<" > "<<" ";
        std::cin >> given_answer;
        std::cin.get();
        if(given_answer == m_answers[i]){ 
            ++count;
        }
        std::cout << std::endl;
    }
    std::cout << "Your scored "<<count<<" out of "<<m_answers.size()<<std::endl<<std::endl;
}