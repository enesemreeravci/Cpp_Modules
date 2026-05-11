#include "ClapTrap.hpp"

int main()
{
    ClapTrap robot;
    ClapTrap robot2("Enes");

    robot.attack("Somone");
    robot.takeDamage(8);
    robot.beRepaired(4);
    robot2.attack("Enemy");
    robot2.takeDamage(5);
    robot2.beRepaired(3);
    robot2.takeDamage(20);
    robot2.attack("Another Enemy");
    robot2.beRepaired(5);

    return (0);
}