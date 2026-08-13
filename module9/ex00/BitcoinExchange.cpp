#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
    *this = copy;   
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
    if(this != &rhs)
    {
        this->dataBase = rhs.dataBase;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static bool ConvertValueToDouble(const std::string& ValueStr, double& result)
{
    std::istringstream iss(ValueStr);
    double converted = 0.0;
    // reads the double and verifies there are no extra trailing characters
    if((iss >> converted) && (iss >> std::ws).eof())
    {
        result = converted;
        return true;
    }
    return false;
}   


bool BitcoinExchange::OpenAndReadTheData(const std::string &file)
{
    std::ifstream infile(file.c_str());
    if(!infile.is_open())
    {
        std::cerr << "Error: Cannot open the file" << std::endl;
        return false;
    }
    // std::cout << "We opened the file." << std::endl; 
    std::string line;
    std::getline(infile, line); // this line will read the first row and it will skip the first row before while loop
    while(std::getline(infile, line)) // one line at a time
    {
        std::string::size_type pos;
        pos = line.find(',');
        if(pos == std::string::npos)
        {
            std::cerr << "Comma not found" << std::endl;
            return false;
        }
        std::string date = line.substr(0, pos);
        std::string value = line.substr(pos + 1); // + 1 for skipping comma
        double dValue;
        if(!ConvertValueToDouble(value, dValue))
        {
            std::cerr << "Error: While value converting." << std::endl;
            return false;
        }

        dataBase.insert(std::make_pair(date, dValue));
    }
    return true;
}