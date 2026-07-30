#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

void test_empty_array()
{

    std::cout << "-----------------TESTING EMPTY ARRAYS----------------------" << std::endl;
    Array<int> numbers;
    Array<int> numbers2(10);
    std::cout << "size of numbers array: " << numbers.getSize() << std::endl;
    std::cout << "size of numbers2 array: " << numbers2.getSize() << std::endl; 

    Array<int> numbers3 = numbers2; // copy constructor called
    std::cout << "size of numbers2 array: " << numbers2.getSize() << std::endl;
    std::cout << "size of numbers3 array: " << numbers3.getSize() << std::endl;     

    numbers = numbers3; // copy asignment operator
    std::cout << "size of numbers array: " << numbers.getSize() << std::endl;
    std::cout << "size of numbers3 array: " << numbers3.getSize() << std::endl;     

    try
    {
        std::cout << "Elements of numbers: " << std::endl;
        for(int i = 0; i < 10; i++)
        {
            std::cout << numbers[i] << " ";
        }
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "First catch block! Exception: " << e.what() << std::endl;

    }
    try
    {
        std::cout << "Filling numbers2 with random values: " << std::endl;
        std::srand(std::time(NULL));
        for(unsigned int i = 0; i < numbers2.getSize(); i++)
        {
            numbers2[i] = std::rand() % 100;
        }
        for(unsigned int i = 0; i < numbers2.getSize(); i++)
        {
            std::cout << numbers2[i] << " " ;
        }
        std::cout << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cout << "Second catch block! Exception " << e.what() << std::endl;    
    }
}

int main()
{
    test_empty_array();
}

/*
#define MAX_VAL 10
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 10000;
        numbers[i] = value;
        mirror[i] = value;
        std::cout <<  value << " ";
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}
*/