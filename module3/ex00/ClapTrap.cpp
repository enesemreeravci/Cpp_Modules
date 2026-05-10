#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitPoints(10), energyPoints(10), attackDamage(10)
{
    std::cout << "Default constructor called." << std::endl;
}
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(10)
{
    this->name = name;
    std::cout << "Name constructor called for " << name << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other)
{
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    std::cout << "Copy constructor called." << std::endl;

    // *this = other;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy assignment operator called" << std::endl;

    //self-assignment protection
    if(this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints  = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called." << std::endl; 
}

void ClapTrap::attack(const std::string& target)
{
    if(hitPoints > 0 && energyPoints > 0)
        std::cout << getName() << " attacks to " << target << " causing " << getDamage() << " points of damage." << std::endl;
    else
        std::cout << name << " cannot attack due to @hitPoints or @energyPoints" << std::endl;

}
void takeDamage(unsigned int amount)
{
    hitPoints -= amount;
    if(hitPoints < 0)
        hitPoints = 0;
    std::cout << name << " takes " << amount << " points of damage!" << " Hitpoints left: " << hitPoints << std::endl;  
}

std::string ClapTrap::getName()
{
    return name;
}

unsigned int ClapTrap::getDamage()
{
    return attackDamage;
}

unsigned int ClapTrap::getHitPoints()
{
    return hitPoints;
}
unsigned int ClapTrap::getEnergyPoints()
{
    return energyPoints;
}
