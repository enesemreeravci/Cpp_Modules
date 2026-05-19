#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "[Cat] default constructor called" << std::endl;
}


Cat::Cat(const std::string& type) : Animal(type)
{
    std::cout << "[Cat] " << type << " constructor called" << std::endl;
}

Cat::Cat(const Cat& rhs) : Animal(rhs)
{
    std::cout << "[Cat] copy constructor called" << std::endl; 
}

Cat& Cat::operator=(const Cat& rhs)
{
    if(this != &rhs)
    {
        Animal::operator=(rhs);
    }
    std::cout << "[Cat] copy assignment operator called "<< std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "[Cat] destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "[Cat]: makeSound() called and sound : MEOW MEOW" << std::endl;
}
