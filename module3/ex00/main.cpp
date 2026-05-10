#include "ClapTrap.hpp"

int main()
{
    ClapTrap robot("Bob");

    robot.attack("Enemy");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.takeDamage(20);
    robot.attack("Another Enemy");
    robot.beRepaired(5);

    return (0);
}