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

    std::cout << "\n=== TESTING DEEP COPY ===\n";
    
    Dog originalDog;
    originalDog.getBrain()->setIdeas(0, "I love bones");

    std::cout << "Copying originalDog into cloneDog" << std::endl;

    Dog clonedDog = originalDog;

    std::cout << "Changing cloneDog's idea ===\n";
    clonedDog.getBrain()->setIdeas(0, "I want to chase cats");
    std::cout << "Original Dog Idea 0: " << originalDog.getBrain()->getIdeas(0) << std::endl;
    std::cout << "Cloned Dog Idea 0:   " << clonedDog.getBrain()->getIdeas(0) << std::endl;
    
    


    
    return 0;
}