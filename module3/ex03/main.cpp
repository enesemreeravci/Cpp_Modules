#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "\n========== DIAMONDTRAP BASIC TEST ==========\n" << std::endl;

    DiamondTrap diamond("Diamondy");

    diamond.attack("Enemy");
    diamond.takeDamage(40);
    diamond.beRepaired(20);
    diamond.whoAmI();

    std::cout << "\n========== INHERITED SPECIAL FUNCTIONS TEST ==========\n" << std::endl;

    diamond.guardGate();
    diamond.highFivesGuys();

    std::cout << "\n========== DIAMONDTRAP ENERGY TEST ==========\n" << std::endl;

    DiamondTrap battery("DiamondBattery");

    for (int i = 0; i < 51; i++)
        battery.attack("Target");

    std::cout << "\n========== DIAMONDTRAP DEAD TEST ==========\n" << std::endl;

    DiamondTrap dead("DeadDiamond");

    dead.takeDamage(150);
    dead.attack("Enemy");
    dead.beRepaired(10);
    dead.whoAmI();

    std::cout << "\n========== COPY CONSTRUCTOR TEST ==========\n" << std::endl;

    DiamondTrap copyDiamond(diamond);

    copyDiamond.attack("Copied Enemy");
    copyDiamond.whoAmI();

    std::cout << "\n========== ASSIGNMENT OPERATOR TEST ==========\n" << std::endl;

    DiamondTrap assigned;

    assigned = diamond;
    assigned.attack("Assigned Enemy");
    assigned.whoAmI();

    std::cout << "\n========== CONSTRUCTION / DESTRUCTION CHAIN TEST ==========\n" << std::endl;

    {
        DiamondTrap temp("TemporaryDiamond");
        temp.attack("Short-lived enemy");
        temp.whoAmI();
    }

    std::cout << "\n========== END OF MAIN ==========\n" << std::endl;

    return (0);
}