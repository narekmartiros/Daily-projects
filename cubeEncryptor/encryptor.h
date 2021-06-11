
#ifndef ENCRYPTOR
#define ENCRYPTOR

#include "cube.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <time.h>
#include <algorithm>

class encryptor{
public:
    void splitter(const std::string& filename);
    int encryptor_size();
    cube& get_cube(int index);
    std::string rot_dir();
    void encrypt();
    void save_encryption(const std::string& filename);
    void save_key(const std::string& filename);

private:
    std::ifstream file1;
    std::vector<cube> m_enc;
    std::vector<std::string> m_splitted;
};

#endif // encryptor