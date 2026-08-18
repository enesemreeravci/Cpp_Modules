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
static bool IsValidDateFormat(const std::string& date);
bool BitcoinExchange::OpenInputFileAndRead(const std::string& userFile)
{
    std::ifstream userInput(userFile.c_str());
    if(!userInput.is_open())
    {
        std::cerr << "Error occurred while opening file" << std::endl;
        return false;
    }
    std::string line;
    std::getline(userInput, line); // skip the first row
    while(std::getline(userInput, line))
    {
        std::string::size_type pos;
        pos = line.find('|');
        if(pos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, pos);
        std::string value = line.substr(pos + 1);
        std::string trimmedDate = Trim(date);
        std::string trimmedValue = Trim(value);
        double inputValue;
        double rate;
        if(!IsValidDateFormat(trimmedDate))
        {
            std::cerr << "Error: bad input =>" << line  << std::endl;
            continue;
        }
        if(!ConvertValueToDouble(trimmedValue, inputValue))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if(inputValue < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if(inputValue > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        if(!RateProcessor(trimmedDate, rate))
        {
            std::cerr << "Error: bad input => " << trimmedDate << std::endl;
            continue;
        }
        double result = inputValue * rate;
        std::cout << trimmedDate << " => " <<
                    trimmedValue << " = " << 
                    result << std::endl;
    
       // std::cout << "[" << trimmedDate << "]";
     //   std::cout << "[" << trimmedValue << "]" << std::endl;
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
static bool IsLeapYear(int year);

static bool IsValidDateFormat(const std::string& date)
{
    if(date.length() != 10)
        return false;
    if(date[4] != '-' || date[7] != '-')
        return false;
    
    for(size_t i = 0; i < date.length(); i++)
    {
        if(i == 4 || i == 7)
            continue;
        if(!isdigit(date[i]))
            return false;
    }
    int year, month, day;
    std::istringstream YearStr(date.substr(0, 4));
    std::istringstream MonthStr(date.substr(5, 2)); 
    std::istringstream DayStr(date.substr(8, 2));
    YearStr >> year;
    MonthStr >> month;
    DayStr >> day;
    if(month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    if(month == 2)
    {
        if(IsLeapYear(year) && day >  29)
            return false;
        if(!IsLeapYear(year) && day > 28)
            return false;
    }
    if((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    return true;
}

static bool IsLeapYear(int year)
{
    if((year % 400 == 0) || 
        (year % 4 == 0 && year % 100 != 0))    
        return true;
    return false;
}
bool BitcoinExchange::RateProcessor(const std::string& requestedDate, double& rate)
{
    if(dataBase.empty())
        return false;
    std::map<std::string, double>::const_iterator it;
    it = dataBase.lower_bound(requestedDate);
    if(it == dataBase.begin())
    {
        if(it->first == requestedDate)
        {
            rate = it->second;
            return true;
        }
    }
    else if(it == dataBase.end())
    {
        --it;
        rate = it->second;
        return true;
    }
    else if(it->first == requestedDate)
    {
        rate = it->second;
        return true;
    }
    else 
    {
        it--;
        rate = it->second;
        return true;
    }
    return false;
}
