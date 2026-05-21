#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
    
    const WrongAnimal* kobi = new WrongCat();
    const WrongAnimal* pamuk = new WrongCat("pamuk");

    std::cout << kobi->getType() << " " << std::endl;
    std::cout << pamuk->getType() << " " << std::endl;

    kobi->makeSound();
    pamuk->makeSound();

    delete kobi;
    delete pamuk;
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    
    // const Animal* i = new Cat();

    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;

    // i->makeSound(); //will output the cat sound!
    // j->makeSound();
    // meta->makeSound();
        

    // delete meta;
    // delete i;
    // delete j;

    
    return 0;
}