#include "encryptor.h"
#include <fstream>
#include <iostream>

int main(){
    encryptor encrypt;
    encrypt.splitter("enc.txt");
    encrypt.encrypt();
    encrypt.save_encryption("dec.txt");
}