#include "Form.h"

Forms::~Forms(){
    db.close();
}

void Forms::create_form(const std::string& filename){
    form.open(filename);
    db.open("Forms_DB");
    db << filename << std::endl;
    create_question(filename);
    form.close();
}

void Forms::create_question(const std::string& filename){
    std::ifstream dbs("Forms_DB");
    std::string form_name;
    while(!dbs.eof()) {
        std::string temp;
        std::getline(dbs, temp);
        if(temp == filename){
            form_name = temp;
            break;
        }
    }
    dbs.close();

    int done = 1;
    int question_count = 1;
    while(done == 1) {
        std::cout << "\nPlease insert questions\n" << std::endl;
        std::string question;
        std::string answer;
        int answer_count;
        int answer_counter = 1;
        std::cout << question_count << " ";
        std::getline(std::cin, question);
        form << question_count << "  " << question << std::endl;
        std::cout << "Number of answer options? \n";
        std::cin >> answer_count;
        std::cin.get();
        while(answer_counter <= answer_count){
            std::cout << answer_counter << " ";
            std::getline(std::cin, answer);
            form << "   " << answer_counter << " " << answer << std::endl;
            answer.clear();
            ++ answer_counter;
        }
        form << std::endl << "----------- \n" << std::endl;
        std::cout << "\n Right answer is - ";
        int right_answer;
        std::cin >> right_answer;
        std::cin.get();
        db << right_answer << " ";
        ++question_count;
        std::cout << "\n 1) to add new question     2) to finish" << std::endl;
        std::cin >> done;
        std::cin.get();
    }
   db << std::endl;
}

void Forms::preview_form (const std::string& filename) {
    std::ifstream dbs ("Forms_DB");
    std::string form_name;
    int even = 0;
    while(!dbs.eof()){
        std::string temp;
        std::getline(dbs, temp);
        if(even == 0 || even % 2 == 0){
        if(temp == filename){
            form_name = temp;
            break;
        }
        }
        ++even;
    }
    dbs.close();
    std::ifstream preview_form(form_name);
    while(!preview_form.eof()) {
        std::string form_rows;
        std::getline(preview_form, form_rows);
        if(even == 0 || even%2 == 0){
            std::cout << form_rows << std::endl;
        }
    }
    form.close();
}

void Forms::preview_questionaries() {
    std::ifstream dbs("Forms_DB");
    std::string form_name;
    int even = 0;
    while(!dbs.eof()) {
        std::cout << std::endl;
        std::string temp;
        std::getline(dbs, temp);
        if(even == 0 || even%2 == 0){
            std::cout << temp << "  ";
        }
        ++even;
    }
    std::cout << std::endl << std::endl;
    dbs.close();
 }
