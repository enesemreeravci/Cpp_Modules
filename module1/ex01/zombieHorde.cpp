#include "Zombie.hpp"

// when creating an array with new[], objects are first created with 
// the default consturctor so we need a way to assign values afterward
// setName()
Zombie* zombieHorde( int N, std::string name )
{
    Zombie *horde = new Zombie[N];
    if (N <= 0)
        return NULL;
    for (int i=0; i < N; i++)
    {
        horde[i].setName(name);
    }
    return horde;
}