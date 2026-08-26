#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

class PmergeMe
{
    private:
        std::vector<int>& vector_numbers;
        std::deque<int>& deque_numbers;
    
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe& copy);
        PmergeMe& operator=(const PmergeMe& rhs);
        ~PmergeMe();

        bool Parse(int argc, char **argv);
};

#endif