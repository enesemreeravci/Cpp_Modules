#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

/*
    std::rand() picks a massive random number (e.g. 24891).
    % 3 squeezes it into: 0, 1, or 2.
    +1 shifts it into:   1, 2, or 3.
*/
Base* generate(void)
{
    // Seed ONCE at the start so numbers change every time you run the program
    std::srand(static_cast<unsigned int>(std::time(NULL))); 
    int randomValue = ((std::rand() % 3) + 1);

    std::cout << "Value: " << randomValue << std::endl;
    
    switch (randomValue)
    {
    case 1:
        std::cout << "Class A instance: " << std::endl;
        return new A();
    case 2:
        std::cout << "Class B instance: " <<  std::endl;
        return new B();
    case 3:
        std::cout << "Class C instance: " << std::endl;
        return new C();
    }
    return nullptr;
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "Object type pointed to by p is: A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "Object type pointed to by p is: B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "Object type pointer to by p is: C" << std::endl;

}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (...)
    {
    }

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (...)
    {
    }
    
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (...)
    {
    }
}

int main()
{   
    Base *obj = generate();

    identify(obj);
    identify(*obj);

    delete obj; 

    return 0;
}