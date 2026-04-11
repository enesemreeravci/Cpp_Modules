#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon &weaponA; 
    public:
        HumanA(std::string name, Weapon &_weapon);
        ~HumanA();

        void attack(void);
};

#endif