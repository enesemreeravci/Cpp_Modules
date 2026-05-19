#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Default")
{
    std::cout << "[WrongAnimal] default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type)
{
    std::cout << "[WrongAnimal] " << type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs) : type(rhs.type)
{
    std::cout << "[WrongAnimal] copy constructor called" << std::endl;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
    if(this != &rhs)
    {
        this->type = rhs.type;
    }
    std::cout << "[WrongAnimal] copy assignment operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "[WrongAnimal] destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "[WrongAnimal] making sound" << std::endl;
}

std::string WrongAnimal::getType()
{
    std::cout << "Type: ";
    return type;
}
