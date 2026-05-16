#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    std::cout << "\n========== FRAGTRAP BASIC TEST ==========\n" << std::endl;

    FragTrap frag("Fraggy");

    frag.attack("Monster");
    frag.takeDamage(40);
    frag.beRepaired(15);
    frag.highFivesGuys();

    std::cout << "\n========== FRAGTRAP ENERGY TEST ==========\n" << std::endl;

    FragTrap battery("FragBattery");

    for (int i = 0; i < 101; i++)
        battery.attack("Target");

    std::cout << "\n========== FRAGTRAP DEAD TEST ==========\n" << std::endl;

    FragTrap dead("DeadFrag");

    dead.takeDamage(150);
    dead.attack("Enemy");
    dead.beRepaired(10);
    dead.highFivesGuys();

    std::cout << "\n========== ZERO DAMAGE / ZERO REPAIR TEST ==========\n" << std::endl;

    FragTrap zero("ZeroFrag");

    zero.takeDamage(0);
    zero.beRepaired(0);

    std::cout << "\n========== COPY CONSTRUCTOR TEST ==========\n" << std::endl;

    FragTrap copyFrag(frag);

    copyFrag.attack("Copied Enemy");
    copyFrag.highFivesGuys();

    std::cout << "\n========== ASSIGNMENT OPERATOR TEST ==========\n" << std::endl;

    FragTrap assigned;

    assigned = frag;
    assigned.attack("Assigned Enemy");
    assigned.highFivesGuys();

    std::cout << "\n========== CONSTRUCTION / DESTRUCTION CHAIN TEST ==========\n" << std::endl;

    {
        FragTrap temp("TemporaryFrag");
        temp.attack("Short-lived enemy");
        temp.highFivesGuys();
    }

    std::cout << "\n========== END OF MAIN ==========\n" << std::endl;

    return (0);
}