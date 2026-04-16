#include "replace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Error: Program usage: <program_name> <filename> <str1> <str2>\n";
        return 1;
    } 
    else
    {
        std::string file_name = argv[1];
        std::string string1 = argv[2];
        std::string string2 = argv[3];
        processFile(file_name, string1, string2);
        return 0;
    }

}