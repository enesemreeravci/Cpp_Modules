#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed\n";
}
void Zombie::announce()
{
    std::cout << name << '\n';
}

void Zombie::setName(std::string name)
{
    this->name = name;
}