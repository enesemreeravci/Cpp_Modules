#include "Animal.hpp"

Animal::Animal() : type("Default")
{
    std::cout << "[Animal] default constructor called" << std::endl;
}

Animal::Animal(const std::string type) : type(type)
{
    std::cout << "[Animal] " << type << " type constructor called" << std::endl;  
}
Animal::Animal(const Animal& rhs) : type(rhs.type)
{
    std::cout << "[Animal] " << "copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
    if(this != &rhs)
    {
        this->type = rhs.type;
    }
    std::cout << "[Animal] copy assignment operator called" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "[Animal] " << type <<  " destructor called" << std::endl;
}