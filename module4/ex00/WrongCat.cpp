#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "[WrongCat] default constructor called" << std::endl;
}

WrongCat::WrongCat(const std::string& type) : WrongAnimal(type)
{
    std::cout << "[WrongCat] " << type << " default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs) : WrongAnimal(rhs)
{
    std::cout << "[WrongCat] copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
    if(this != &rhs)
    {
        WrongAnimal::operator=(rhs);
    }
    std::cout << "[WrongCat] copy assignment operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "[WrongCat] destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "[WrongCat] making sounds" << std::endl;
}