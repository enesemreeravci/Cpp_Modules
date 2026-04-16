#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) :type(type)
{
    std::cout << "Weapon type " << type << " created\n"; // just to see what's going on
}

Weapon::~Weapon()
{
    std::cout << "Weaon type " << type << " destroyed\n";
}

const std::string& Weapon::getType() const
{
    return type;
}

void Weapon::setType(const std::string& type)
{
    this->type = type;
}
