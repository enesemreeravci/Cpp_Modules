#include "easyfind.hpp"
#include <iostream>
#include <vector>


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

        std::vector<int>::iterator it;

        it = easyfind(numbers, 60);
        std::cout << "This is a test, this line will not be printed" << std::endl; 
    
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

}