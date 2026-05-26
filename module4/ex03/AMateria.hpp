#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

// base abstract class
class AMateria
{
    protected:
        std::string type;

    public:
        AMateria();
        AMateria(const std::string& type);
        AMateria(const AMateria& rhs);
        AMateria& operator=(const AMateria& rhs);
        virtual ~AMateria();

        const std::string& getType() const;
        virtual void use(ICharacter& target);
        virtual AMateria* clone() const = 0; 
        // we forced every derived class
        // inherits from this class must implement/override this function

    };

#endif