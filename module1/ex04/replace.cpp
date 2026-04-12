#include "replace.hpp"

bool processFile(const std::string &fileName, const std::string &str1,const std::string &str2)
{
    std::ifstream infile(fileName.c_str());

    if(!infile.is_open())
    {
        std::cerr << "Error: cannot open the file\n";
        return false;
    }

    std::string outputFile = (fileName + ".replace").c_str(); // creates a new file with name +.replace
    std::ofstream outfile(outputFile.c_str());
    if(!outfile.is_open())
    {
        std::cerr << "Error: cannot create the file\n";
        return false;
    }
    std::string line;
    while(std::getline(infile, line)) // one line at a time 
    {
        std::string newLine = replaceAll(line, str1, str2);
        outfile << newLine; 
        if(!infile.eof())
            outfile << '\n';
    }
    return true;

}

std::string replaceAll(const std::string &line, const std::string &str1, const std::string &str2)
{
    std::string result = "";
    int pos = 0;
    std::string::size_type found;
    while(true)
    {
        found = line.find(str1, pos);
        if(str1.empty())
            return line;
        if(found == std::string::npos)
        {
            result += line.substr(pos);
            break;
        }
        result += line.substr(pos, found - pos);
        result += str2;
        pos  = found + str1.length();
    }   
    return result;
}