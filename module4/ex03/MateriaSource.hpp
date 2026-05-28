#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <iostream>
#include <string>

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *materia[4];

    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource& rhs);
        MateriaSource& operator=(const MateriaSource& rhs);
        ~MateriaSource();

        void learnMateria(AMateria* m);
        AMateria* createMateria(const std::string& type);
};

#endif