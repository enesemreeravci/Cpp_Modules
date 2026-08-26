#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
    *this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    if(this != &rhs)
    {
        this->vector_numbers = rhs.deque_numbers;
        this->deque_numbers = rhs.deque_numbers;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

static bool isValidNumber(const std::string& arg)
{
    if(arg.empty())
        return false;
    for(int  i =0; i < arg.size(); i++)
    {
        if(!isdigit(arg[i]))
            return false;
    }
    int value = std::atoi(arg.c_str());
    if(value >= 0 && value <= 2147483647)
        return true;
    return false;
}

bool PmergeMe::Parse(int argc, char **argv)
{
    for(int i = 1; i < argc; i++)
    {
        std::string arg = argv[1];
        if(!isValidNumber(arg))
            return false;
        int value = std::atoi(arg.c_str());
        vector_numbers.push_back(value);
        deque_numbers.push_back(value);
    }
}