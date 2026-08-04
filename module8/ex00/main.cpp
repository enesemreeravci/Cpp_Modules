#include "easyfind.hpp"
#include <iostream>
#include <vector>

// #include <array> 
// it's introduced 
int main(void)
{
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    numbers.push_back(40);

    try
    {
        std::vector<int>::iterator result;
        
        result = easyfind(numbers, 40);
        int index = std::distance(numbers.begin(), result);
        std::cout << "Found: "  << *result << ", at index: " << index << std::endl;
    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}