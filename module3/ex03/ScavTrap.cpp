#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(), isGuardGate(false)
{
    std::cout << "[ScavTrap] " << "default consturctor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), isGuardGate(false)
{
    std::cout << "[ScavTrap] " << name << "consctructor called" << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other), isGuardGate(false)
{
    std::cout << "Copy constructor called. " << std::endl;
}
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "Copy assignment operator called." << std::endl;

    if(this != &other)
    {
        ClapTrap::operator=(other);
        this->isGuardGate = other.isGuardGate;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Deconstructor called" << std::endl;
}
void ScavTrap::attack(const std::string& target)
{
    if (hitPoints <= 0)
    {
        std::cout << "[ScapTrap] " << name << " cannot attack due to @hitPoints." << std::endl;
    }
    else if(energyPoints <= 0)
    {
        std::cout << "[ScapTrap] " << name << " cannot attack due to @energyPoints." << std::endl;
    }
    else
    {
        std::cout << "[ScapTrap] " << name << " attacks " << target << " causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints = energyPoints - 1;
    }
}

void ScavTrap::guardGate(void)
{
    if(isGuardGate == false)
    {
        std::cout <<  "[ScapTrap] " << name << " is in GateKeeper mode!" << std::endl;
    }
    else if (isGuardGate == true)
    {
        std::cout << "[ScapTrap] " << name <<  " is in not GateKeeper mode!" << std::endl;
    }
}