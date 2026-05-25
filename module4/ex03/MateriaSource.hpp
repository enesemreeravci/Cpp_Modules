#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <string>
#include "AMateria.hpp"

class MateriaSource
{
    protected:
        MateriaSource();
        MateriaSource(const MateriaSource& rhs);
        MateriaSource& operator=(const MateriaSource& rhs);
    
    public:
        virtual ~MateriaSource();
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(const std::string& type) = 0;
};

#endif