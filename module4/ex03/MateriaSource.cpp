#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(void)
{
    for(int i = 0; i < 4; i++)
    {
        materia[i] = NULL;
    }
    std::cout << "[MateriaSource] default consturctor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& rhs)
{
    for(int i =0; i < 4; i++)
    {
        if(rhs.materia[i])
            materia[i] = rhs.materia[i]->clone();
        else
            materia[i] = NULL;
    }
    std::cout << "[MateriSource] copy consturctor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
    if(this != &rhs)
    {
        for (int i = 0; i< 4; i++)
        {
            delete materia[i];

            if(rhs.materia[i])
                materia[i] = rhs.materia[i]->clone();
            else
                materia[i] =NULL;
        }
    }
    std::cout << "[MateriaSource] assignment operator called" << std::endl;
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i<4;i++)
    {
        delete materia[i];
    }
    std::cout << "[MateriaSource] destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if(!m)
        return;

    for (int i =0; i< 4; i++)
    {
        if(!materia[i])
        {
            materia[i] = m->clone();
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
    for (int i = 0; i<4; i++)
    {
        if(materia[i] && materia[i]->getType() == type)
            return materia[i]->clone();
    }
    return NULL;
}

