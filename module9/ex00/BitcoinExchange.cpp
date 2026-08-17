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

void BitcoinExchange::PrintDataBase() const
{
    std::map<std::string, double>::const_iterator it;

    it = dataBase.begin();
    while(it != dataBase.end())
    {
        std::cout << it->first << ',';
        std::cout << it->second << std::endl;
        ++it;
    }
    std::cout << "end of printing." << std::endl;
}

static std::string Trim(const std::string& str);

bool BitcoinExchange::OpenInputFileAndRead(const std::string& userFile)
{
    std::ifstream userInput(userFile.c_str());
    if(!userInput.is_open())
    {
        std::cerr << "Error occurred while opening file" << std::endl;
        return false;
    }
    std::string line;
    std::getline(userInput, line);
    while(std::getline(userInput, line))
    {
        std::string::size_type pos;
        pos = line.find('|');
        if(pos == std::string::npos)
        {
            std::cerr << "Vertical bar '|' not found." << std::endl;
            continue;
        }
        std::string date = line.substr(0, pos);
        std::string value = line.substr(pos + 1);
        std::string trimmedDate = Trim(date);
        std::string trimmedValue = Trim(value);
        std::cout << "[" << trimmedDate << "]";
        std::cout << "[" << trimmedValue << "]" << std::endl;
    }
    return true;
}

static std::string Trim(const std::string& str)
{
    const std::string whitespaces = " \t\n\r";
    size_t start = str.find_first_not_of(whitespaces);
    if(start == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(whitespaces);

    std::string res = str.substr(start, last - start + 1);
    return res;
}