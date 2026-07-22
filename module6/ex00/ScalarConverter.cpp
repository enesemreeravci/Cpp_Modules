#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) 
{
    (void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
    if(this != &rhs)
        (void)rhs;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

/*

strtol() : interprets a integer value in a byte string pointer to by str
strtod() : interprets a floating point value in a byte string pointer to by str

*/

static bool isChar(const std::string& str)
{
    if(str.length() == 1 && !std::isdigit(str[0]))
        return true;
    return false;
}
static bool isInt(const std::string& str)
{
    char *end;
    std::strtol(str.c_str(), &end, 10);
    return *end == '\0';
}

static bool isFloat(const std::string& str)
{
    if(str == "+inff" || str == "-inff" || str == "nanf")
        return true;
    char *end;
    std::strtod(str.c_str(), &end);
    return (*end == 'f' && *(end + 1) == '\0');
}

static bool isDouble(const std::string& str)
{
    if(str == "+inf" || str == "-inf" || str == "nan")
        return true;
    char *end;
    std::strtod(str.c_str(), &end);
    return *end == '\0';
}

static void printImpossible(void)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

static void printChar(double value);
static void printInt(double value);
static void printFloat(double value);
static void printDouble(double value);

void ScalarConverter::convert(const std::string& user_input)
{
    double value = 0.0;

    if(isChar(user_input))
        value = static_cast<double>(user_input[0]);
    else if(isInt(user_input))
        value = std::strtod(user_input.c_str(), NULL);
    else if(isFloat(user_input))
        value = std::strtod(user_input.c_str(), NULL);
    else if(isDouble(user_input))
        value = std::strtod(user_input.c_str(), NULL);
    else
    {
        printImpossible();
        return;
    }
    printChar(value);
    printInt(value);
    printDouble(value);
    printFloat(value);

}

static void printInt(double value)
{
   if (std::isnan(value) || !std::isfinite(value))
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    if (value > INT_MAX || value < INT_MIN)
    {   
        std::cout << "int: impossible" << std::endl;
        return;
    }
    int number = static_cast<int>(value);
    std::cout << "int: " << number << std::endl;
}

static void printChar(double value)
{
    if(std::isnan(value) || !std::isfinite(value))
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    if(value > CHAR_MAX || value < CHAR_MIN)
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }

    char c = static_cast<char>(value);

    if (!std::isprint(static_cast<unsigned char>(c)))
    {
        std::cout << "char: Non displayable" << std::endl;
        return;
    }
    std::cout << "char: '" << c << "'" << std::endl;
}

static void printFloat(double value)
{
    float number = static_cast<float>(value);

    std::cout << "float: ";

    if (std::isnan(number))
    {
        std::cout << "nanf" << std::endl;
        return;
    }

    if (std::isinf(number))
    {
        if (number < 0)
            std::cout << "-inff" << std::endl;
        else
            std::cout << "+inff" << std::endl;
        return;
    }

    if (std::floor(number) == number)
    {
        //forces floating-point numbers to be written in fixed-point notation
        std::cout << std::fixed
                  << std::setprecision(1)
                  << number
                  << "f"
                  << std::endl;
    }
    else
    {
        std::cout << number << "f" << std::endl;
    }
}

static void printDouble(double value)
{
    std::cout << "double: ";

    if (std::isnan(value))
    {
        std::cout << "nan" << std::endl;
        return;
    }

    if (std::isinf(value))
    {
        if (value < 0)
            std::cout << "-inf" << std::endl;
        else
            std::cout << "+inf" << std::endl;
        return;
    }
            //the largest possible integer value which is less than or equal to value
    if (std::floor(value) == value)
    {
        std::cout << std::fixed
                  << std::setprecision(1)
                  << value
                  << std::endl;
    }
    else
    {
        std::cout << value << std::endl;
    }
}