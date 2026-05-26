#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character
{   
    private:
        std::string name;
        AMateria* inventory[4];

};

#endif