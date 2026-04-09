#include "Zombie.hpp"

int main()
{
    Zombie *z ; 
    z = newZombie("foo");
    randomChump("foo2");
    z->announce();
    delete z;
    return 0;

}