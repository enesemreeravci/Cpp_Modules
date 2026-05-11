#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Default constructor called." << std::endl;
}
ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(10)
{   
    std::cout << "Name constructor called for " << name << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
    std::cout << "Copy constructor called." << std::endl;
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
    if (hitPoints <= 0)
    {
        std::cout << "[ClapTrap] " << name << " cannot attack due to @hitPoints." << std::endl;
    }
    else if(energyPoints <= 0)
    {
        std::cout << "[ClapTrap] " << name << " cannot attack due to @energyPoints." << std::endl;
    }
    else
    {
        std::cout << "[ClapTrap] " << name << " attacks " << target << " causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints = energyPoints - 1;
    }
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "[ClapTrap] " << name << " is already dead." << std::endl;
    }

    else if (amount >= hitPoints)
    {
        hitPoints = 0;
        std::cout << "[ClapTrap] " << name << " attacked and died." << std::endl;
    }
    else 
    {
        hitPoints = hitPoints - amount;
        std::cout << "[ClapTrap] "<< name << " was attacked. Hit points left : " << hitPoints << std::endl;
    }
}
void ClapTrap::beRepaired(unsigned int amount)
{
    if(hitPoints == 0)
    {
        std::cout << "[ClapTrap] " << name << " is already dead. Cannot be repaired." << std::endl;
    }
    else if (energyPoints <= 0)
    {
        std::cout << "[ClapTrap] " << name << " no energyPoints. Cannot be repaired." << std::endl;
    }
    else 
    {
        hitPoints += amount;
        energyPoints -= 1;
        std::cout << "[ClapTrap] " << name << " is repaired " << amount  << " points. Hit points: " << hitPoints << std::endl; 
    }
}

