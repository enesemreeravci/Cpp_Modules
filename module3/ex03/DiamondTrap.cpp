#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): 
    ClapTrap("default_clap_name"), 
    FragTrap("default"), 
    ScavTrap("default"),
    name("default")
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
    std::cout << "[DiamondTrap]" << " default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name): 
    ClapTrap(name + "_clap_name"),
    FragTrap(name),
    ScavTrap(name),
    name(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;

    std::cout << "[DiamondTrap] " << this->name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other):
    ClapTrap(other),
    FragTrap(other),
    ScavTrap(other),
    name(other.name)
{
    std::cout << "[DiamondTrap] copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    
    if(this != &other)
    {
        ClapTrap::operator=(other);
        
        this->name = other.name;
    }
    
    std::cout << "[DiamondTrap] " << this->name << " copy assignment operator called" << std::endl;
    return *this;

}

DiamondTrap::~DiamondTrap()
{
    std::cout << "[DiamondTrap] " << this->name << " destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "[DiamondTrap] " << this->name <<
    ", [ClapTrap name] " << ClapTrap::name << std::endl; 
}