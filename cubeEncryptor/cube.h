#ifndef CUBE
#define CUBE

#include <string>

class cube{
    public:
    void up();
    void down();
    void left();
    void right();
    void fill_cube(const std::string enc);
    std::string& get_cube();
    void set_dir(std::string str);
    std::string& get_direction();

    private:
    std::string m_cube{"        "};
    std::string m_dir;
};

#endif //cube

  