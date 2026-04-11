#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
    private:
        std::string type;

    public:
        Weapon(std::string type); // consturctor
        ~Weapon();
        std::string getType();        // getter
        void setType(std::string type); // setter
};

#endif