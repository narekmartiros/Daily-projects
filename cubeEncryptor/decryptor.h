#ifndef DECRYPTOR
#define DECRYPTOR

#include <fstream>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
#include "encryptor.h"

class decryptor{
    public:
    void parse_key(const std::string filename);
    void parse_encryption(const std::string filename);
    void decrypt();
    void save_decryption(const std::string filename);
    int get_size_dec();
    int get_size_key();

    private:
    std::vector<std::vector<std::string>> m_keys;
    std::vector<cube> m_dec_spl;
    std::string m_enc_cube;
};

#endif //decryptor

