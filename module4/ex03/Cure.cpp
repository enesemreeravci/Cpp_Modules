#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void) : AMateria("Cure")
{
    std::cout << "[Cure] default constructor called" << std::endl;
}

Cure::Cure(const Cure& rhs) : AMateria(rhs)
{
    std::cout << "[Cure] copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& rhs)
{
    if(this != &rhs)
    {
        AMateria::operator=(rhs);
    }
    std::cout << "[Cure] assignment operator called" << std::endl;
    return *this;
}

Cure::~Cure()
{
    std::cout << "[Cure] destructor called" << std::endl;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; 

}

Cure* Cure::clone() const
{
    Cure* clone = new Cure();
    return clone;
}