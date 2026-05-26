#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
    public:
        Cure(void);
        Cure(const Cure& rhs);
        Cure& operator=(const Cure& rhs);
        ~Cure();

        void use(ICharacter& target);
        Cure* clone(void) const;        

};

#endif