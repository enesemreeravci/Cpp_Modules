#include "ClapTrap.hpp"

int main()
{
    std::cout << "\n========== BASIC TEST ==========\n" << std::endl;

    ClapTrap robot;
    ClapTrap robot2("Enes");

    robot.attack("Someone");
    robot.takeDamage(8);
    robot.beRepaired(4);

    robot2.attack("Enemy");
    robot2.takeDamage(5);
    robot2.beRepaired(3);
    robot2.takeDamage(20);
    robot2.attack("Another Enemy");
    robot2.beRepaired(5);

    std::cout << "\n========== ENERGY TEST ==========\n" << std::endl;

    ClapTrap energyTest("Battery");

    for (int i = 0; i < 11; i++)
        energyTest.attack("Target");

    std::cout << "\n========== ZERO DAMAGE / ZERO REPAIR TEST ==========\n" << std::endl;

    ClapTrap zeroTest("Zero");

    zeroTest.takeDamage(0);
    zeroTest.beRepaired(0);

    std::cout << "\n========== COPY CONSTRUCTOR TEST ==========\n" << std::endl;

    ClapTrap copy(robot2);
    copy.attack("Copied Enemy");

    std::cout << "\n========== ASSIGNMENT OPERATOR TEST ==========\n" << std::endl;

    ClapTrap assigned;

    assigned = robot;
    assigned.attack("Assigned Enemy");

    std::cout << "\n========== END ==========\n" << std::endl;

    return (0);
}