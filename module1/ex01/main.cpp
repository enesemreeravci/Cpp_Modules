#include "Zombie.hpp"

int main()
{
    Zombie *horde = zombieHorde(5, "emre");

    for (int i = 0; i < 5;i++)
    {
        horde[i].announce();
    }
    delete[] horde;
}