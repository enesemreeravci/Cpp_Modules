#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
    std::cout << "Zombie " << name << " created" << std::endl;
}
Zombie::~Zombie()
{
    std::cout << "Zombie " << name << " destroyed" << std::endl;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiinnnzzzZ..." << std::endl;
}