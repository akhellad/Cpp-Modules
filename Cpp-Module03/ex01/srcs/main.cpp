// main.cpp
#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main() {
	// Crée une instance de ClapTrap
	ClapTrap claptrap("CL4P-TP");

	// Attaque et réparation pour ClapTrap
	claptrap.attack("Bandit");
	claptrap.takeDamage(3);
	claptrap.beRepaired(2);

	// Crée une instance de ScavTrap
	ScavTrap scavtrap("SC4V-TP");

	// Attaque, réparation et capacité spéciale pour ScavTrap
	scavtrap.attack("Bandit");
	scavtrap.takeDamage(3);
	scavtrap.beRepaired(2);

	scavtrap.guardGate();

	return 0;
}
