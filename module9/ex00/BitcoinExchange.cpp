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

static double ConvertValueToDouble(const std::string& ValueStr)
{
    std::istringstream iss(ValueStr);
    double converted = 0.0;
    // reads the double and verifies there are no extra trailing characters
    if((iss >> converted) && (iss >> std::ws).eof())
    {
        return converted;
    }
    //returns 0.0 if the string was not a valid double
    return 0.0;

    // i must figure this out, if it fails, func returns 0.0 which is too risky 
}   //
bool BitcoinExchange::OpenAndReadTheData(std::string &file) const
{
    std::ifstream infile(file.c_str());
    if(!infile.is_open())
    {
        std::cerr << "Error: Cannot open the file" << std::endl;
        return false;
    }
    // std::cout << "We opened the file." << std::endl; 
    std::string line;
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
        ConvertValueToDouble(value);
    }

    return true;

}