#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Default")
{
    std::cout << "[WrongAnimal] default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type)
{
    std::cout << "[WrongAnimal] " << type << " constructor called" << std::endl;
}
