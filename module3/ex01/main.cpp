#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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

    std::cout << "\n========== DESTRUCTOR TEST ==========\n" << std::endl;

    return 0;


}