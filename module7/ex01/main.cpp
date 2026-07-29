#include "iter.hpp"

#include <iostream>
#include <string>

void printStr(const std::string& val)
{
    std::cout << val <<  " ";
} 

int main()
{   
    int arr[] = {1, 2, 3, 4, 5};
    int arr2[] = {43};
    char letters[] = {'a', 'b' , 'c' , 'd', '*'};
    std::string str[4] =  {"this", "is", "a", "test"};

    int len =  sizeof(arr) / sizeof(arr[0]);
    
    // Function templates cannot be passed directly; they must first be instantiated.
    // in this case print still is a parameter so compiler cannot deduce for print
    // thats why I used explicitly <int or string>
    iter(arr, len, print<int>);
    std::cout << std::endl;
    iter(arr, len, increment<int>);
    std::cout << std::endl;
    iter(str, 4, print<std::string>);
    std::cout << std::endl;
    iter(letters, 5, print<char>);
    std::cout << std::endl;
    iter(arr2, 1, decrement<int>);
    std::cout << std::endl; 
    

    // // printStr is a concrete function; 'print' is only a function template.
    iter(str, 4, printStr); 
    std::cout << std::endl;
}