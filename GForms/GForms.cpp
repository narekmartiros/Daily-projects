#include "Admin.h"
#include <iostream>

std::string filename();
void create_quiz(Admin& admin);
void preview_quiz(Admin& admin);
void preview_all_quizes(Admin& admin);

void preview_quiz(User& user);
void preview_all_quizes(User& user);
void take_quiz(User& user);

void user_logic(User& user);
void admin_logic(Admin& admin);


int main() {
    User user;
    Admin admin;
    std::cout<<"\nWelcome to <GForms>!!!"<<std::endl;
    std::cout<<"\n---------------------"<<std::endl;
    std::cout<<"\nEnter 1 for admin"<<std::endl;
    std::cout<<"Enter 2 for user"<<std::endl;
    int user_type;
    std::cin>>user_type;

    if(user_type==1) {
        admin_logic(admin);
    }
    else if(user_type==2) {
        user_logic(user);
    }
    else {
        std::cout<<"\nWrong user type"<<std::endl;
    }
}

std::string filename() {
    std::cout<<"Please insert the name of the quize."<<std::endl;
    std::string quiz_filename;
    std::string quiz_name;
    std::cin>>quiz_name;
    std::cin.get();
    quiz_filename=quiz_name+".txt";
    return quiz_filename;
}

void create_quiz(Admin& admin) {
    int done=1;
    while(done==1){
        admin.create_quiz(filename());
        std::cout<<"To create new quiz insert <1>"<<std::endl;
        std::cout<<"\n1) to add new quiz     2) to finish"<<std::endl;
        std::cin>>done;
        std::cin.get();
    }
}

void preview_quiz(Admin& admin) {
    admin.preview_quiz(filename());
}

void preview_quiz(User& user) {
    user.preview_questionary(filename());
}

void preview_all_quizes(User& user) {
    user.preview_questionaries();
}

void preview_all_quizes(Admin& admin) { 
    admin.preview_quizs();
}

void take_quiz(User& user) {
    user.take_quiz(filename());
}

void user_logic(User& user) {
    bool done=false;
    while(!done){
    int selection;
        std::cout<<"\n1) See all quizes"<<std::endl;
        std::cout<<"2) Preview a quize"<<std::endl;
        std::cout<<"3) Take a quize"<<std::endl;
        std::cout<<"0) To exit"<<std::endl;
        std::cin>>selection;
        switch (selection){
            case 0:
                done=true;
                break;
            case 1:
                preview_all_quizes(user);
                break;
            case 2:
                preview_quiz(user);
                break;
            case 3:
                take_quiz(user);
                break;
            default:
                std::cout<<"Unknown command!!!"<<std::endl;
        }
    }
}

void admin_logic(Admin& admin){
    bool done=false;
    while(!done){
        int selection;
        std::cout<<"\n1) Create a quiz"<<std::endl;
        std::cout<<"2) Preview all quizes"<<std::endl;
        std::cout<<"3) Preview a quiz"<<std::endl;
        std::cout<<"0) To exit"<<std::endl;
        std::cin>>selection;
        switch (selection){
            case 0:
                done=true;
                break;
            case 1:
                create_quiz(admin);
                break;
            case 2:
                preview_all_quizes(admin);
                break;
            case 3:
                preview_quiz(admin);
                break;
            default:
                std::cout<<"Unknown command!!!"<<std::endl;
        }
    }
}
