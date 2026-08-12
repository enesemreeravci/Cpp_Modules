#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <ostream>
#include <map>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cerr << "Wrong usage" << std::endl;
        return 1;
    }
    std::string file  = argv[1];
    BitcoinExchange btc;
    btc.OpenAndReadTheData(file);
    return 0;
}