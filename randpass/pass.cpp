#include <string>
#include <iostream>
#include <time.h>
#include <algorithm>

int main(){
    std::string A={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::string a={"abcdefghijklmnopqrstuvwzyx"};
    std::string integer={"0123456789"};
    std::string symbol={")&^%$#@!"};

    std::string password;
  
    srand(time(0));
    int vrand;
    
    int min=8;
    int max=24;
    int x=min+rand()%(max-min+1);
 
    int Acoutn=0;
    int symbolc=0;
    int count=0;
   
    while(count<x/3){
        password+=a[vrand=rand()%26];
        if(Acoutn>2){
            password+=A[vrand=rand()%26];
        }
        password+=integer[vrand=rand()%10];
        if(symbolc<2){
            password+=symbol[vrand=rand()%8];
        }
         ++Acoutn;
         ++symbolc;
         ++count;
    }

std::random_shuffle(password.begin(),password.end());
std::cout<<password<<std::endl;

int AcountCHeck=0;
int ASymb=0;

for(auto& x:password){
        if((int)x>=65&&(int)x<=90){
            ++AcountCHeck;
        }
    }

for(auto& y: symbol){
        for(auto& x: password){
            if(x==y){
                ++ASymb;
            }
        }    
    }

std::cout<<std::endl;
if(AcountCHeck>=3&&ASymb==2){
    std::cout<<"Password is valid";
   }
}

