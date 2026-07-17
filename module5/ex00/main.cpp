#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Enes", 100);
        b1.printBureaucrat();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    try 
    {
        std::cout << "Creating a bureaucrat called Emre" << std::endl;
        Bureaucrat b2("Emre", 1);
        b2.printBureaucrat();
        std::cout << "Emre's grade decrementing" << std::endl;
        b2.dec();
        std::cout << "--------------------" << std::endl;
        b2.printBureaucrat();
        std::cout << "Emre's grade incrementing" << std::endl;
        b2.inc();
        b2.printBureaucrat();
        //b2.inc();
        std::cout << "--------------------" << std::endl;
    }
    catch (const std::exception& e) // we can access all derived class with this object.
    {
        std::cout << e.what() << std::endl;
    }
}