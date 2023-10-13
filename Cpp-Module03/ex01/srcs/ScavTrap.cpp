// ScavTrap.cpp
#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "ScavTrap " << name << " is born with 100 hit points, 50 energy points, and 20 attack damage!" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << name << " is destroyed with a bang!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (getHitPoints() > 0 && energyPoints > 0) {
		std::cout << "ScavTrap " << name << " attacks " << target << " with a furious strike, causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "ScavTrap " << name << " can't attack. Not enough hit points or energy points." << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
}

