#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <istream>
#include <ostream>
#include <fstream>
#include <iostream>
#include <string>

bool processFile(const std::string &fileName, const std::string &str1,const std::string &str2);
std::string replaceAll(const std::string &line, const std::string &str1, const std::string &str2);

#endif