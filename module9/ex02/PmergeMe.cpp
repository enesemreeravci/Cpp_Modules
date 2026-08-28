#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
    *this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    if(this != &rhs)
    {
        this->vector_numbers = rhs.vector_numbers;
        this->deque_numbers = rhs.deque_numbers;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

static bool isValidNumber(const std::string& str, int& result)
{
    if(str.empty())
        return false;
    for(int i = 0; i < str.size(); i++)
    {
        if(!isdigit(str[i]))
            return false;
    }
    std::stringstream ss(str);
    long value;
    ss >> value;
    if(result <= 0 && result >= 2147483647)
        return false;
    result = static_cast<int>(value);
    return true;
}

bool PmergeMe::ParseInput(int argc, char **argv)
{
    for(int i = 1; i < argc; i++)
    {
        int result = 0;
        std::string arg = argv[i];
        if(!isValidNumber(arg, result))
            return false;
        vector_numbers.push_back(result);
        deque_numbers.push_back(result);
    }
    return true;
}

static void printOriginal(const std::vector<int>& vec)
{
    std::vector<int>::const_iterator it;
    
    std::cout << "Before: " << std::endl;
    it = vec.begin();
    while (it != vec.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

std::vector<int> PmergeMe::SortVector(const std::vector<int>& vec)
{
    size_t size = vec.size();
    if(size <= 1)   
        return vec;
    std::vector< std::pair<int, int> > paired_vector;
    bool hasLeftover = false;
    int leftoverValue = 0;
    for(size_t i = 0; i + 1 < size; i += 2)
    {
        // first is small, second is large
        int first = vec[i];
        int second = vec[i + 1];
        if(first > second)  
            std::swap(first, second);
        paired_vector.push_back(std::make_pair(first, second));
    }
    if(size % 2 == 1)
    {
        hasLeftover = true;
        leftoverValue = vec[size - 1];
    }

    std::vector<int> winners;
    for(size_t i = 0; i < paired_vector.size(); i++)
    {
        winners.push_back(paired_vector[i].second);
    }
    // we recursively sorting larger values into sortedWinners
    std::vector<int> sortedWinners = SortVector(winners);

    std::vector<std::pair<int, int> > orderedPairs;
    for(size_t i = 0; i < sortedWinners.size(); i++)
    {
        for(size_t j = 0; j < paired_vector.size(); j++)
        {
            if(paired_vector[j].second == sortedWinners[i])
            {
                orderedPairs.push_back(paired_vector[j]);
                break;
            } 
        }
    }
    std::vector<int> mainChain;
    mainChain.push_back(orderedPairs[0].first);
    for(size_t i = 0; i < orderedPairs.size(); i++)
    {
        mainChain.push_back(orderedPairs[i].second);
    }
    
    std::vector<int> pending;
    for(size_t i = 1; i < orderedPairs.size(); i++)
    {
        pending.push_back(orderedPairs[i].first);
    }
}