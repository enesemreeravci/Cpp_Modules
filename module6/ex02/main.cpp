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

    switch (randomValue)
    {
    case 1:
        A *obj_a = new A();
        std::cout << "Class A instance: " << obj_a << std::endl;
        return obj_a; 
    case 2:
        B *obj_b = new B();
        std::cout << "Class B instance: " << obj_b << std::endl;
        return obj_b;
    case 3:
        C *obj_c = new C();
        std::cout << "Class C instance: " << obj_c << std::endl;
        return obj_c;
    }


}



/*
void identify(Base* p);
It prints the actual type of the object pointed to by p: "A", "B", or "C".
*/

/*
void identify(Base& p);
It prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
inside this function is forbidden.
*/

int main()
{   
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    int randomValue = ((std::rand() % 3) + 1);
    std::cout << randomValue;
    return 0;
}