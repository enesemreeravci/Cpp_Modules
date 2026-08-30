#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if(argc <  2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    PmergeMe obj;
    if(!obj.ParseInput(argc, argv))
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    obj.Sort();
}