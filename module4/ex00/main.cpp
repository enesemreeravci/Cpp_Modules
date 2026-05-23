#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
    std::cout << "\n=== SUBJECT TEST ===\n";

    const Animal* meta = new Animal();
    const Animal* dog  = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\n=== TYPE TEST ===\n";

    std::cout << meta->getType() << std::endl;
    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;


    std::cout << "\n=== SOUND TEST ===\n";

    meta->makeSound();
    dog->makeSound();
    cat->makeSound();

    std::cout << "\n=== DESTRUCTION TEST ===\n";

    delete meta;
    delete dog;
    delete cat;

    std::cout << "\n=== STACK OBJECT TEST ===\n";

    Dog Max;
    Cat Kobi;

    Max.makeSound();
    Kobi.makeSound();

    std::cout << "\n=== COPY CONSTRUCTOR TEST ===\n";

    Dog copyDog(Max);
    Cat copyCat(Kobi);

    copyDog.makeSound();
    copyCat.makeSound();

    std::cout << "\n=== ASSIGNMENT OPERATOR TEST ===\n";

    Dog assignDog;
    Cat assignCat;

    assignDog = Max;
    assignCat = Kobi;

    assignDog.makeSound();
    assignCat.makeSound();

    std::cout << "\n=== POLYMORPHISM TEST ===\n";

    Animal* animals[4];

    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int i = 0; i < 4; i++)
    {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }

    std::cout << "\n=== ARRAY DELETE DEST ===\n";

    for (int i =0; i < 4; i++)
    {
        delete animals[i];
    }

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "wrongMeta " << wrongMeta->getType() << std::endl;
    std::cout << "wrongCat " << wrongCat->getType() << std::endl;

    std::cout << "\nWrongAnimal Sound: " << std::endl;
    wrongMeta->makeSound();
    std::cout << "\nWrongCat sound through WrongAnimal pointer" << std::endl;
    wrongCat->makeSound();

    std::cout << "\n=== WrongAnimal DELETE TEST ===\n";
    
    delete wrongMeta;
    delete wrongCat;

    std::cout << "\n=== END OF PROGRAM ===\n";
    return 0;
}