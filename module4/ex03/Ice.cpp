#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void) : AMateria("Ice")
{
    std::cout << "[Ice] default constructor called" << std::endl;
}

Ice::Ice(const Ice& rhs) : AMateria(rhs)
{
    std::cout << "[Ice] copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& rhs)
{
    if(this != &rhs)
    {
        AMateria::operator=(rhs);
    }
    std::cout << "[Ice] assignment operator called" << std::endl;
    return *this;
}

void Ice::use(ICharacter& target) 
{
    std::cout << "* shoots an ice bolt at " << target.getName() << std::endl; 
}

Ice* Ice::clone(void) const
{
    Ice* clone = new Ice();
    return clone;
}