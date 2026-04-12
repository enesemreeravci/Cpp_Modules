#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
    std::cout << "human name: "  << name <<  "created: " << WeaponB->getType() << '\n';
}

HumanB::~HumanB()
{

}
void HumanB::attack()
{
    std::cout << "human name: " << name << "now attacking with a weapon: " << WeaponB->getType() << '\n';
}

void HumanB::setWeapon(Weapon &weapon)
{
    WeaponB = &weapon;
}
