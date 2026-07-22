#include "ScalarConverter.hpp"

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cout << "Wrong usage" << std::endl;
        return 1;
    }
    std::string user_input = av[1];
    ScalarConverter::convert(user_input);

    return 0;
}