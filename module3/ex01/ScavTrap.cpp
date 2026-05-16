#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
    std::cout << "[ScavTrap] " << "default constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "[ScavTrap] " << name << " constructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
    std::cout << "[ScavTrap] " << "Copy constructor called. " << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    
    if(this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "[ScavTrap] " << "Copy assignment operator called." << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "[ScavTrap] " << name << " destructor called" << std::endl;
}
void ScavTrap::attack(const std::string& target)
{
    if (hitPoints <= 0)
    {
        std::cout << "[ScavTrap] " << name << " cannot attack because it has no hit points." << std::endl;
    }
    else if(energyPoints <= 0)
    {
        std::cout << "[ScavTrap] " << name << " cannot attack because it has no energy points." << std::endl;
    }
    else
    {
        std::cout << "[ScavTrap] " << name << " attacks " << target << " causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints = energyPoints - 1;
    }
}

void ScavTrap::guardGate(void)
{
    std::cout <<  "[ScavTrap] " << name << " is now in GateKeeper mode!" << std::endl;
}