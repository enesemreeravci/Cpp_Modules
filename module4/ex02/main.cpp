#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
   std::cout << "\n=== SUBJECT TEST ===\n";

    //const Animal* meta = new Animal();  here we will have an error, cause we can't  instantiate an object from abstract class
    const Animal* dog  = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\n=== TYPE TEST ===\n";

   // std::cout << meta->getType() << std::endl;
    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;


    std::cout << "\n=== SOUND TEST ===\n";

   // meta->makeSound();
    dog->makeSound();
    cat->makeSound();
}

