#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>

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

        bool ParseInput(int argc, char **argv);
        bool SortVector(const std::vector<int>& vec);
};

#endif