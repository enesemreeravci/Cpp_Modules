#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice(void);
        Ice(const Ice& rhs);
        Ice& operator=(const Ice& rhs);
        ~Ice(void);

        void use(ICharacter& target);
        Ice* clone(void) const;
};

#endif