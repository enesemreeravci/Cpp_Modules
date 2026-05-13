#include "DiamondTrap.hpp"

int main()
{
    std::cout << "\n========== CLAPTRAP TEST ==========\n" << std::endl;

    ClapTrap clap("Clappy");

    clap.attack("Bandit");
    clap.takeDamage(5);
    clap.beRepaired(3);



    std::cout << "\n========== SCAVTRAP TEST ==========\n" << std::endl;

    ScavTrap scav("Guardian");

    scav.attack("Enemy");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();



    std::cout << "\n========== FRAGTRAP TEST ==========\n" << std::endl;

    FragTrap frag("Destroyer");

    frag.attack("Target");
    frag.takeDamage(40);
    frag.beRepaired(25);
    frag.highFivesGuys();



    std::cout << "\n========== DIAMONDTRAP TEST ==========\n" << std::endl;

    DiamondTrap diamond("Diamond");

    diamond.attack("Ultimate Boss");
    diamond.takeDamage(30);
    diamond.beRepaired(15);

    // inherited abilities
    diamond.guardGate();
    diamond.highFivesGuys();

    // DiamondTrap special function
    diamond.whoAmI();



    std::cout << "\n========== ENERGY TEST ==========\n" << std::endl;

    ClapTrap energy("LowBattery");

    for (int i = 0; i < 11; i++)
        energy.attack("Training Dummy");



    std::cout << "\n========== COPY TEST ==========\n" << std::endl;

    DiamondTrap original("Original");

    DiamondTrap copy(original);

    DiamondTrap assigned;
    assigned = original;

    copy.whoAmI();
    assigned.whoAmI();



    std::cout << "\n========== DESTRUCTOR TEST ==========\n" << std::endl;

    return 0;
}