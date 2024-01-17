/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:11:07 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/30 16:15:02 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ClapTrap.hpp"
#include "../includes/FragTrap.hpp"

int main() {
	// Test avec ClapTrap
	ClapTrap claptrap("CL4P-TP");
	claptrap.attack("Bandit");
	claptrap.takeDamage(3);
	claptrap.beRepaired(2);
	std::cout << "CL4P-TP's hit points: " << claptrap.getHitPoints() << std::endl;

	// Test avec FragTrap
	FragTrap fragtrap("FR4G-TP");
	fragtrap.attack("Spiderman");
	fragtrap.takeDamage(20);
	fragtrap.beRepaired(15);
	fragtrap.highFivesGuys();
	std::cout << "FR4G-TP's hit points: " << fragtrap.getHitPoints() << std::endl;

	return 0;
}
