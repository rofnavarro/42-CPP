#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

void new_file(std::ofstream &to, std::string tmp)
{
    to << tmp;
    to.close();
}

void find_and_replace(std::string &tmp, std::string s1, std::string s2)
{
    std::size_t found = 0;

    while ((found = tmp.find(s1, found)) != std::string::npos)
    {
        if (tmp.empty())
            std::cout << "It appears you have submitted an empty file." << std::endl;
        tmp.erase(found, s1.length());
        tmp.insert(found, s2);
        found += s2.length();
    }
}

std::string content_to_string(std::ifstream &from)
{
    std::string ret;
    std::ostringstream tmp;

    tmp << from.rdbuf();
    ret = tmp.str();
    from.close();

    return (ret);
}

int file_check(std::ifstream &from)
{
    if (!from.is_open() || from.fail()){

        std::cout << "Please inform a valid filename." << std::endl;
        from.close();
        return (1);
    }
    return (0);
}

int arg_check(int argc)
{
    if (argc !=4){

        std::cout << "Please insert <filename> <search_term> <replace_term>." << std::endl;
        return (1);
    }
    return (0);
}

int main ( int argc, char **argv ){

    std::ifstream   from(argv[1]);
    std::string filename = argv[1];
	filename += ".replace";
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string tmp;


    if (arg_check(argc) == 1 )
        return (1);
    if (file_check(from) == 1)
        return (2);
    std::ofstream to(filename.c_str());
    tmp = content_to_string(from);
    find_and_replace(tmp, s1, s2);
    new_file(to, tmp);
    return (0);
}