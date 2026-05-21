#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{

    std::cout << "\n====== CREATING AND FILLING ANIMAL ARRAY ======\n";

    const int size = 4;
    Animal* animal[size];

    for(int i = 0; i < size; i++)
    {
        if(i < size / 2)
        {
            animal[i] = new Dog();
        }
        else
        {
            animal[i] = new Cat();
        }
    }
    std::cout << std::endl;
    for (int i =0; i< size; i++)
    {
        animal[i]->makeSound();
    }
    std::cout << std::endl;
    for (int i =0; i <size; i++)
    {
        std::cout << animal[i]->getType() << std::endl;
    }
    std::cout << std::endl;
    for(int i =0; i < size; i++)
    {
        delete animal[i];
    }



    
    


    
    return 0;
}