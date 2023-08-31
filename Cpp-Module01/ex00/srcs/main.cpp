/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 23:36:06 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/31 23:36:24 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.h"

int main() {
    Zombie zombie1("Alice");
    zombie1.announce();

    Zombie* zombie2 = newZombie("Bob");
    zombie2->announce();
    delete zombie2;

    randomChump("Charlie");

    return 0;
}