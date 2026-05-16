#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "\n========== CLAPTRAP BASIC TEST ==========\n" << std::endl;

    ClapTrap clap("Clappy");

    clap.attack("Bandit");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n========== SCAVTRAP BASIC TEST ==========\n" << std::endl;

    ScavTrap scav("Guardian");

    scav.attack("Enemy");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "\n========== SCAVTRAP ENERGY TEST ==========\n" << std::endl;

    ScavTrap battery("Battery");

    for (int i = 0; i < 51; i++)
        battery.attack("Target");

    std::cout << "\n========== SCAVTRAP DEAD TEST ==========\n" << std::endl;

    ScavTrap dead("DeadScav");

    dead.takeDamage(150);
    dead.attack("Enemy");
    dead.beRepaired(10);
    dead.guardGate();

    std::cout << "\n========== ZERO DAMAGE / ZERO REPAIR TEST ==========\n" << std::endl;

    ScavTrap zero("ZeroScav");

    zero.takeDamage(0);
    zero.beRepaired(0);

    std::cout << "\n========== COPY CONSTRUCTOR TEST ==========\n" << std::endl;

    ScavTrap copyScav(scav);

    copyScav.attack("Copied Enemy");
    copyScav.guardGate();

    std::cout << "\n========== ASSIGNMENT OPERATOR TEST ==========\n" << std::endl;

    ScavTrap assigned;

    assigned = scav;
    assigned.attack("Assigned Enemy");
    assigned.guardGate();

    std::cout << "\n========== CONSTRUCTION / DESTRUCTION CHAIN TEST ==========\n" << std::endl;

    {
        ScavTrap temp("Temporary");
        temp.attack("Short-lived enemy");
    }

    std::cout << "\n========== END OF MAIN ==========\n" << std::endl;

    return (0);
}