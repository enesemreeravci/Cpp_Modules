#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& _weapon) : name(name), weaponA(_weapon)
{
    std::cout << "human name: "  << name <<  "created: " << weaponA.getType() << std::endl;
}

HumanA::~HumanA()
{

}

void HumanA::attack()
{
    std::cout << "human name: " << name << "now attacking with a weapon: " << weaponA.getType() << std::endl;
}