#include "Span.hpp"
#include <iostream>

// implement more test cases here

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    for(unsigned int i = 0; i < 5; i++)
        std::cout << sp[i] << " ";
    std::cout << std::endl;
   // std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}
