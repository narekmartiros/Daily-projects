#include "cube.h"

void cube::fill_cube(std::string enc){
    if(enc.size()==m_cube.size()){
        m_cube=enc;
    }
    else{
    int s=m_cube.size()-enc.size();
    m_cube=enc;
        for(int i=0; i<s;++i){
            m_cube+="0";
        }
    }    
}

std::string& cube::get_cube(){
    return m_cube;
}

void cube::up(){
    std:: string cube=m_cube;
    cube[0]=m_cube[1];
    cube[1]=m_cube[3];
    cube[2]=m_cube[0];
    cube[3]=m_cube[2];
    cube[4]=m_cube[5];
    cube[5]=m_cube[7];
    cube[6]=m_cube[4];
    cube[7]=m_cube[6];
    m_cube=cube;
}

void cube::down(){
    std:: string cube=m_cube;
    cube[0]=m_cube[2];
    cube[1]=m_cube[0];
    cube[2]=m_cube[3];
    cube[3]=m_cube[1];
    cube[4]=m_cube[6];
    cube[5]=m_cube[4];
    cube[6]=m_cube[7];
    cube[7]=m_cube[5];
    m_cube=cube;
  }

void cube::left(){
    std:: string cube=m_cube;
    cube[0]=m_cube[4];
    cube[1]=m_cube[0];
    cube[2]=m_cube[6];
    cube[3]=m_cube[2];
    cube[4]=m_cube[5];
    cube[5]=m_cube[1];
    cube[6]=m_cube[7];
    cube[7]=m_cube[3];
    m_cube=cube;
}

void cube::right(){
    std:: string cube=m_cube;
    cube[0]=m_cube[1];
    cube[1]=m_cube[5];
    cube[2]=m_cube[3];
    cube[3]=m_cube[7];
    cube[4]=m_cube[0];
    cube[5]=m_cube[4];
    cube[6]=m_cube[2];
    cube[7]=m_cube[6];
    m_cube=cube;
}

void cube::set_dir(std::string str){
    m_dir+=str+" ";
}

std::string& cube::get_direction(){
    return m_dir;
}
