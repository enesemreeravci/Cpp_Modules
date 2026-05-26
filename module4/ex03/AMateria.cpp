#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void)
{
    std::cout << "[AMateria] default constructor" << std::endl;
}

AMateria::AMateria(const std::string& type) : type(type)
{
    std::cout << "[AMateria] " << type << " constructor called" << std::endl;   
}

AMateria::AMateria(const AMateria& rhs) : type(rhs.type)
{
    std::cout << "[AMateria] copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
    if(this != &rhs)
    {
        this->type = rhs.type;
    }
    std::cout << "[AMateria] assignment operator called" << std::endl;
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "[AMateria] virtual destructor called" << std::endl;
}

const std::string& AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "[AMateria] using a Materia on a " << target.getName() << " !" << std::endl;
}

