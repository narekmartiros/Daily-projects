#include "decryptor.h"
#include <fstream>
#include <iostream>

int main(){
    encryptor encrypt;
    decryptor decrypt;
    encrypt.splitter("enc.txt");
    encrypt.encrypt();
    encrypt.save_key("key.txt");
    encrypt.save_encryption("dec.txt");
    decrypt.parse_key("key.txt");
    decrypt.parse_encryption("dec.txt");
    decrypt.decrypt();
    decrypt.save_decryption("Decrypted.txt");
}