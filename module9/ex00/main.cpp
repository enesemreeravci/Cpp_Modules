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
    if(!btc.OpenAndReadTheData("data.csv"))
        return 1;
    //btc.PrintDataBase();
    if(!btc.OpenInputFileAndRead(file))
        return 1;
    return 0;
}