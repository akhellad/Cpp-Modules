/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 23:36:06 by akhellad          #+#    #+#             */
/*   Updated: 2023/09/01 00:25:12 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.h"
#include <iostream>

int main() {
    int numZombies = 5;
    Zombie* horde = zombieHorde(numZombies, "Horde Zombie");

    for (int i = 0; i < numZombies; ++i) {
        horde[i].announce();
    }
    delete[] horde;
    return 0;
}