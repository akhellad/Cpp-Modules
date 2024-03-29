/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:58:17 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/30 15:59:18 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
	std::cout << "ClapTrap " << name << " is born!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << name << " is destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (hitPoints > 0 && energyPoints > 0) {
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	} else {
		std::cout << "ClapTrap " << name << " can't attack. Not enough hit points or energy points." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hitPoints > 0 && amount < static_cast<unsigned int>(hitPoints)) {
		hitPoints -= static_cast<int>(amount);
		std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " can't take any more damage. It's out of hit points." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hitPoints > 0 && energyPoints > 0) {
		hitPoints += static_cast<int>(amount);
		energyPoints --;
		std::cout << "ClapTrap " << name << " is repaired and gains " << amount << " hit points!" << std::endl;
	} else if (hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " can't be repaired. It's out of hit points." << std::endl;
	} else {
		std::cout << "ClapTrap " << name << " can't be repaired. It's out of energy points." << std::endl;
}
}
