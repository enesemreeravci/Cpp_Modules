#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << "\n=== BASIC POLYMOORPHISM TEST ===\n";

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    std::cout << "\n=== ANIMAL ARRAY TEST ===\n";

    Animal* animals[4];
    for (int i=0; i < 2; i++)
    {
        animals[i] = new Dog();
    }
    for (int i = 2; i < 4; i++)
    {
        animals[i] = new Cat();
    }   
    for (int i =0; i < 4; i++)
    {
        std::cout << animals[i]->getType() << " ";
        animals[i]->makeSound();
    }
    for (int i = 0;  i< 4; i++)
    {
        delete animals[i];
    } 


    std::cout << "\n=== DOG BRAIN DEEP COPY TEST ===\n" << std::endl;

    Dog dog1;
    dog1.getBrain()->setIdeas(0, "I want a bone");
    dog1.getBrain()->setIdeas(1, "I want to run");

    Dog dog2(dog1);

    std::cout << "dog1 idea[0]: " << dog1.getBrain()->getIdeas(0) << std::endl;
    std::cout << "dog2 idea[0]: " << dog2.getBrain()->getIdeas(0) << std::endl;

    dog2.getBrain()->setIdeas(0, "I am a copied dog");

    std::cout << "\nAfter changing dog2 idea[0]: " << std::endl;
    std::cout << "dog1 idea[0]: " << dog1.getBrain()->getIdeas(0) << std::endl;
    std::cout << "dog2 idea[0]: " << dog2.getBrain()->getIdeas(0) << std::endl;

    std::cout << "\n=== CAT BRAIN ASSIGNMENT TEST ===\n" << std::endl;

    Cat cat1;
    cat1.getBrain()->setIdeas(0, "I want a fish");
    cat1.getBrain()->setIdeas(1, "I want to sleep");

    Cat cat2;
    cat2 = cat1;
    std::cout << "\nAfter assigning cat1 to cat1" << std::endl;
    std::cout << "cat1 idea[0]: " << cat1.getBrain()->getIdeas(0) << std::endl;
    std::cout << "cat2 idea[0]: " << cat2.getBrain()->getIdeas(0) << std::endl;

    cat2.getBrain()->setIdeas(0, "I am a copied cat");

    std::cout << "\nAfter changing cat2 idea[0]: " << std::endl;
    std::cout << "cat1 idea[0]: " << cat1.getBrain()->getIdeas(0) << std::endl;
    std::cout << "cat2 idea[0]: " << cat2.getBrain()->getIdeas(0) << std::endl;
    
    std::cout << "\n=== SELF ASSIGNMENT TEST ===\n";

    dog1 = dog1;
    cat1 = cat1;
    std::cout << "dog1 idea[0]: " << dog1.getBrain()->getIdeas(0) << std::endl;
    std::cout << "cat1 idea[0]: " << cat1.getBrain()->getIdeas(0) << std::endl;

    std::cout << "\n========== END ==========\n" << std::endl;

    return 0;
}

/*
std::cout << "\n=== TESTING DEEP COPY ===\n";

Dog originalDog;
originalDog.getBrain()->setIdeas(0, "I love bones");

std::cout << "Copying originalDog into cloneDog" << std::endl;

Dog clonedDog = originalDog;

std::cout << "Changing cloneDog's idea ===\n";
clonedDog.getBrain()->setIdeas(0, "I want to chase cats");
std::cout << "Original Dog Idea 0: " << originalDog.getBrain()->getIdeas(0) << std::endl;
std::cout << "Cloned Dog Idea 0:   " << clonedDog.getBrain()->getIdeas(0) << std::endl;
*/