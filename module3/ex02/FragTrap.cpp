#include "FragTrap.hpp"


FragTrap::FragTrap()
{
    std::cout << "[FragTrap] " << "default constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}
FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
    std::cout << "[FragTrap] " << name << "constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
    std::cout << "[FragTrap] " << "copy constructor called" << std::endl; 
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "[FragTrap] " << "copy assignment operator called" << std::endl;
    
    if(this != &other)
    {
        FragTrap::operator=(other);
    }
    return *this;
}

void FragTrap::attack(const std::string& target)
{
    if (hitPoints <= 0)
    {
        std::cout << "[FragTrap] " << name << " cannot attack due to @hitPoints." << std::endl;
    }
    else if(energyPoints <= 0)
    {
        std::cout << "[FragTrap] " << name << " cannot attack due to @energyPoints." << std::endl;
    }
    else
    {
        std::cout << "[FragTrap] " << name << " attacks " << target << " causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints = energyPoints - 1;
    }
}

void FragTrap::highFiveGuys(void)
{
    std::cout << "[FragTrap] " << name << "give me a high five!" << std::endl; 
}