#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

/*
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
        std::cout << "Elements of numbers: " << std::endl; // it will fill with zeros because of our constructor
        for(unsigned int i = 0; i < numbers.getSize(); i++)
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

void test_different_data_types()
{
    std::cout << "-----------------------------TESTING WITH DIFFERENT DATA TYPES--------------------------" << std::endl;

    Array<std::string> str;
    Array<std::string> str2(50);
    
    
    std::cout << "size of str: " << str.getSize() << std::endl;
    std::cout << "size of str2: " << str2.getSize() << std::endl;
    
    Array<std::string> str3 = str2; //copy const called

    try
    {
        for(unsigned int i = 0; i < str2.getSize(); i++)
        {
            std::cout << str[i] << " ";
        }
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    
    try
    {
        for(unsigned int i = 0; i < str2.getSize(); i++)
        {
            str2[i] = "e";
        }
        for(unsigned int i = 0; i < str2.getSize(); i++)
        {
            std::cout << str2[i] << " ";
        }
        std::cout << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl; 
    }
    
    Array<double> arrayDouble(10);

    try
    {
        std::cout << "Filling arrayDouble with random double values: " << std::endl;
        std::srand(std::time(NULL));
        for(unsigned int i = 0; i < arrayDouble.getSize(); i++)
        {
            arrayDouble[i] = static_cast<double>(rand() % RAND_MAX);
        }
        for(unsigned int i = 0; i < arrayDouble.getSize(); i++)
        {
            std::cout << arrayDouble[i] << " " ;
        }
        std::cout << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception " << e.what() << std::endl;    
    }
}

void test_read_and_write_to_array()
{
    Array<int> arr(3);
    Array<int> arr2;
    try
    {
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 3;

        for(unsigned int i = 0; i < arr.getSize(); i++)
        {
            std::cout << "arr[i] = " << arr[i] << " ";
        }
        std::cout << std::endl;
        
        arr2 = arr; // copy constructor
        for(unsigned int i = 0; i < arr2.getSize(); i++)
        {
            arr[i] = i * 10;
        }
        for(unsigned int i = 0; i < arr2.getSize(); i++)
        {
            std::cout << "arr[i] = " << arr[i] << " ";
        } 
        std::cout << std::endl;

        std::cout << arr[4] << std::endl;

        std::cout << "test for catch, this line will not print" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

}

int main()
{
    test_empty_array();
    test_different_data_types();
    //test_read_and_write_to_array();
}
*/

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
        // to see the values
        //std::cout <<  value << " "; 
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
