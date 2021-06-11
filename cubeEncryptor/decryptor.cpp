#include "decryptor.h"

void decryptor::parse_key(const std::string filename){
    std::ifstream file1(filename);
    std::string temp_s;
    std::vector<std::string> tmp;
    while (!file1.eof()){
      std::string m;
		std::getline(file1,temp_s);
		std::istringstream ss(temp_s);
		while(ss>>m){
         std::string s=m;
			tmp.push_back(s);
		}
      m_keys.push_back(tmp);
      tmp.clear();
	}
    file1.close();
}

void decryptor::parse_encryption(const std::string filename){
    std::ifstream file1(filename);
    while(!file1.eof()){
        std::string s;
        s=file1.get();
        m_enc_cube+=s;
    }
    m_enc_cube.erase(m_enc_cube.size()-1);

    std::string s;
    for(int i=0;i<m_enc_cube.size();i+=8){
        s+=m_enc_cube.substr(i,8);
        cube st;
        st.fill_cube(s);
      m_dec_spl.push_back(st);
        s.clear();
    } 
    file1.close();    
}

void decryptor::decrypt(){
    for(int i=0; i<m_dec_spl.size();++i){
        for(int j=m_keys[i].size()-1; j>=1;--j){
            if(m_keys[i][j]=="R:"){
                m_dec_spl[i].left();
            }
            if(m_keys[i][j]=="U:"){
                m_dec_spl[i].down();
            }
            if(m_keys[i][j]=="D:"){
                m_dec_spl[i].up();
            }
            if(m_keys[i][j]=="L:"){
                m_dec_spl[i].right();
            }
        }
    }
}

void decryptor::save_decryption(const std::string filename){
    std::ofstream of(filename);
    for(int i=0;i<m_dec_spl.size();++i){
        of<<m_dec_spl[i].get_cube();
    }
    of.close();
}

int decryptor::get_size_dec(){
    return m_dec_spl.size();
}

 int decryptor::get_size_key(){
    return m_keys.size();
 }