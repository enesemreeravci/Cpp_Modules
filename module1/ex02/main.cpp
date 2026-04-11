#include <iostream>

int main()
{
    std::string str;
    str = "HI THIS IS BRAIN";

    // a string to pointer to the string 
    std::string* stringPTR = &str;

    // a reference to the string
    std::string &stringREF = str;
    std::cout << "Mem adress of the string variable: " << &str << '\n';
    std::cout << "Mem address of held by stirngPTR: " <<  &stringPTR << '\n';
    std::cout << "Mem address held by stringREF: " << &stringREF << '\n';

    std::cout << '\n';

    std::cout << "The value of the string variable: " << str << '\n';
    std::cout << "The value pointed to by stringPTR: " << *stringPTR << '\n';
    std::cout << "The value pointed to by stringREF: " << stringREF << '\n'; 

}
