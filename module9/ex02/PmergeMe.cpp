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
    if (str.empty())
        return false;
        
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }

    std::stringstream ss(str);
    long value;
    ss >> value;

    // Check if stringstream failed (e.g., severe overflow) or left remaining characters
    if (ss.fail() || !ss.eof())
        return false;

    // Strictly validate positive integer range [1, INT_MAX]
    if (value <= 0 || value > INT_MAX)
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

// static void printOriginal(const std::vector<int>& vec)
// {
//     std::vector<int>::const_iterator it;
    
//     std::cout << "Before: " << std::endl;
//     it = vec.begin();
//     while (it != vec.end())
//     {
//         std::cout << *it << " ";
//         ++it;
//     }
//     std::cout << std::endl;
// }
size_t PmergeMe::Jacobsthal(size_t n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}
std::vector<size_t> PmergeMe::BuildInsertionOrder(size_t pendingSize)
{
    std::vector<size_t> order;

    if (pendingSize == 0)
        return order;

    size_t previousJacob = 1;
    size_t jacobIndex = 3;

    while (order.size() < pendingSize)
    {
        size_t currentJacob = Jacobsthal(jacobIndex);
        // Convert b-number to pending[] index.
        // pending[0] = b2, pending[1] = b3, etc

        size_t upper = currentJacob;
        // Don't go beyond the number of b-elements we actually have.
        // pendingSize elements means the largest b is b(pendingSize + 1).
        if (upper > pendingSize + 1)
            upper = pendingSize + 1;

        // Insert this Jacobsthal group backwards.
        // Example: 3 -> 2 gives b3, b2.
        for (size_t b = upper; b > previousJacob; --b)
        {
            size_t pendingIndex = b - 2;

            if (pendingIndex < pendingSize)
                order.push_back(pendingIndex);
        }
        previousJacob = currentJacob;
        ++jacobIndex;
    }
    return order;
}

void PmergeMe::BinaryInsert(std::vector<int>& mainChain,
                            int value,
                            size_t upperBound)
{
    size_t left = 0;
    size_t right = upperBound;

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;

        if (value < mainChain[mid])
            right = mid;
        else
            left = mid + 1;
    }

    mainChain.insert(mainChain.begin() + left, value);
}
std::vector<int> PmergeMe::SortVector(const std::vector<int>& vec)
{
    size_t size = vec.size();

    if (size <= 1)
        return vec;

    std::vector<std::pair<int, int> > unsortedPairs;

    bool hasLeftover = false;
    int leftoverValue = 0;

    for (size_t i = 0; i + 1 < size; i += 2)
    {
        int first = vec[i];
        int second = vec[i + 1];
        // first one is small second one is large number
        if (first > second)
            std::swap(first, second);

        unsortedPairs.push_back(std::make_pair(first, second));
    }

    if (size % 2 == 1)
    {
        hasLeftover = true;
        leftoverValue = vec[size - 1];
    }

    std::vector<int> winners;
    for(size_t i = 0; i < unsortedPairs.size(); i++)
    {
        winners.push_back(unsortedPairs[i].second);
    }
    // we recursively sorting larger values into sortedWinners
    std::vector<int> sortedWinners = SortVector(winners);
    std::vector<bool> used(unsortedPairs.size(), false);
    std::vector<std::pair<int, int> > winnerSortedPairs; // same pairs but reorderes after winners are sorted
    for(size_t i = 0; i < sortedWinners.size(); i++)
    {
        for(size_t j = 0; j < unsortedPairs.size(); j++)
        {
            if (!used[j] && unsortedPairs[j].second == sortedWinners[i])
            {
                winnerSortedPairs.push_back(unsortedPairs[j]);
                used[j] = true;
                break;
            }
        }
    }
    std::vector<int> mainChain;
    mainChain.push_back(winnerSortedPairs[0].first);
    for(size_t i = 0; i < winnerSortedPairs.size(); i++)
    {
        mainChain.push_back(winnerSortedPairs[i].second);
    }
    std::vector<int> pending;

    for (size_t i = 1; i < winnerSortedPairs.size(); ++i)
    {
        pending.push_back(winnerSortedPairs[i].first);
    }

    std::vector<size_t> insertionOrder =
        BuildInsertionOrder(pending.size());

    for (size_t i = 0; i < insertionOrder.size(); ++i)
    {
        size_t pendingIndex = insertionOrder[i];

        int value = pending[pendingIndex];

        int partner =
            winnerSortedPairs[pendingIndex + 1].second;

        size_t partnerPosition = 0;

        while (partnerPosition < mainChain.size()
            && mainChain[partnerPosition] != partner)
        {
            ++partnerPosition;
        }

        BinaryInsert(mainChain, value, partnerPosition);
    }

    if (hasLeftover)
    {
        BinaryInsert(mainChain,
                    leftoverValue,
                    mainChain.size());
    }

    return mainChain;
}

void PmergeMe::Sort()
{
    std::vector<int> sortedVector = SortVector(vector_numbers);

    // temporary test
    for (size_t i = 0; i < sortedVector.size(); ++i)
        std::cout << sortedVector[i] << " ";

    std::cout << std::endl;
}

