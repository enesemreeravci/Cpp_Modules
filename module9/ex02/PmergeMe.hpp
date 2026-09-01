#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <sstream>
#include <climits>
#include <cctype>
#include <sys/time.h>

class PmergeMe
{
    private:
        std::vector<int> vector_numbers;
        std::deque<int> deque_numbers;
    
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe& copy);
        PmergeMe& operator=(const PmergeMe& rhs);
        ~PmergeMe();

        bool ParseInput(int argc, char **argv);
        std::vector<int> SortVector(const std::vector<int> &vec);
        std::vector<size_t> BuildInsertionOrder(size_t pendingSize);
        size_t Jacobsthal(size_t n);
        void BinaryInsert(std::vector<int>& mainChain,
                            int value,
                            size_t upperBound);

        std::deque<int> SortDeque(const std::deque<int>& deq);
        void BinaryInsertDeque(std::deque<int>& mainChain,
                       int value,
                       size_t upperBound);
        void Sort();

    };

#endif