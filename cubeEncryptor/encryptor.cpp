#include "encryptor.h"

void encryptor::save_encryption(const std::string& filename){
    std::ofstream of(filename);
      for(int i=0;i<m_enc.size();++i){
        of<<m_enc[i].get_cube();
    }
    of.close();
}
void encryptor::save_key(const std::string& filename){
    std::ofstream of(filename);
    for(int i=0;i<m_enc.size();++i){
        of<<i<<": "<<m_enc[i].get_direction()<<std::endl;
    }
    of.close();
}

void encryptor::splitter(const std::string& filename){
    file1.open(filename);
    std::string temp;
    while(!file1.eof()){
        std::string s;
        s=file1.get();
        temp+=s;
    }
    temp.erase(temp.size()-1);

    std::string s;
    for(int i=0;i<temp.size();i+=8){
        s+=temp.substr(i,8);
        cube st;
        st.fill_cube(s);
        m_enc.push_back(st);
        s.clear();
    } 
    file1.close();       
}

int encryptor::encryptor_size(){
    return m_enc.size();
}

cube& encryptor::get_cube(int index){
    return m_enc[index];
}

void encryptor::encrypt(){
    std::vector<std::string> rot{"U:","D:","R:","L:"};
    srand(time(0));
    for(int j=0;j<m_enc.size();++j){
        for(int i=0;i<rand()%10+2;++i){
            if(rot[rand()%4]=="R:"){
                m_enc[j].right();
                m_enc[j].set_dir("R:");
            }
            if(rot[rand()%4]=="L:"){
                m_enc[j].left();
                m_enc[j].set_dir("L:");
            }
            if(rot[rand()%4]=="U:"){
                m_enc[j].up();
                m_enc[j].set_dir("U:");
            }
            if(rot[rand()%4]=="D:"){
                m_enc[j].down();
                m_enc[j].set_dir("D:");
            }
        }     
    }
}


