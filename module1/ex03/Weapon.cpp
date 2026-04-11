#include "Weapon.hpp"

Weapon::Weapon(std::string type) :type(type)
{
    std::cout << "Weapon type " << type << " created\n"; // just to see what's going on
}

Weapon::~Weapon()
{
    std::cout << "Weaon type " << type << " destroyed\n";
}

std::string Weapon::getType()
{
    return type;
}

void Weapon::setType(std::string type)
{
    this->type = type;
}
