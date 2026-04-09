#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
    std::cout << "Zombie " << name << "created\n";
}
Zombie::~Zombie()
{
    std::cout << "Zombie " << name << "destroyed\n";
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiinnnzzzZ...\n";
}