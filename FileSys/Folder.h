#ifndef FOLDER
#define FOLDER

#include <map>
#include <memory>


class Folder {
public:
    Folder();
    void create(const std::string& name);
    void create_file(const std::string filename);
    void remove(const std::string& name) ;
    const std::string& get_name()const;
    void set_name(const std::string& name) ;
    std::shared_ptr<Folder> get_folder(const std::string& name) ;
    void print_folder()const;

private:
    std::map<std::string, std::shared_ptr<Folder>> m_folder;
    std::string m_folder_name{};
    std::string m_file_name{};
    std::shared_ptr<Folder> m_parent_folder=nullptr;
};

#endif // Folder