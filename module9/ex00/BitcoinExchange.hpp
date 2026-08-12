#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <string>

class BitcoinExchange
{
    private:
        std::map<std::string, double> dataBase; // export csv file to this container

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& rhs);
        ~BitcoinExchange();
  
        
        bool OpenAndReadTheData(std::string& file) const;
};

#endif