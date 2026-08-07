#include "Span.hpp"
#include <iostream>
#include <ctime>

void print_Span(Span& span)
{
    for(unsigned int i = 0; i < span.getSize() ; i++)
    {
        std::cout << span[i] << " ";
    }
    std::cout << std::endl;
}
void test_case_1()
{
    try
    {
        std::cout << "Testing Span either full or not" << std::endl;
        Span sp_test(2);
        sp_test.addNumber(10);
        sp_test.addNumber(20);
        print_Span(sp_test);
        //sp_test.addNumber(30); 
        // expected to throw spanfullexception 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}
void test_case_2()
{
    try
    {
        std::cout << "Testing Span to find shortest/longest span" << std::endl;
        Span sp_test(6);
        sp_test.addNumber(5);
        sp_test.addNumber(12);
        sp_test.addNumber(9);
        sp_test.addNumber(1);
        sp_test.addNumber(2);
        sp_test.addNumber(9);
        std::cout << "Longest span: " << sp_test.longestSpan() << std::endl;
        std::cout << "Shortest span: " << sp_test.shortestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void test_case_3()
{
    try
    {
        Span sp_test(10000);
        std::srand(std::time(NULL));
        std::vector<int> temp;

        for(unsigned int i = 0; i < 10000; i++)
        {
            temp.push_back(std::rand());    
        }
        sp_test.addRange(temp.begin(), temp.end());
        std::cout << "Longest span: " << sp_test.longestSpan() << std::endl;
        std::cout << "Shortest span: " << sp_test.shortestSpan() << std::endl;
        //print_Span(sp_test);
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    // test_case_1();
    // test_case_2();
    // test_case_3();
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << std::endl;
    print_Span(sp);
    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    return 0;
}
