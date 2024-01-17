/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:05:34 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/30 16:05:36 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

int main() {
	ClapTrap claptrap("CL4P-TP");

	claptrap.attack("Bandit");
	claptrap.takeDamage(3);
	claptrap.beRepaired(2);

	ScavTrap scavtrap("SC4V-TP");

	scavtrap.attack("Bandit");
	scavtrap.takeDamage(3);
	scavtrap.beRepaired(2);

	scavtrap.guardGate();

	return 0;
}
