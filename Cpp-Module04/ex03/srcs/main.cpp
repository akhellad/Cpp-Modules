/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:27:59 by akhellad          #+#    #+#             */
/*   Updated: 2023/12/01 15:40:46 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/Character.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include <iostream>
#include <vector>

int main() {
    std::vector<AMateria*> fallenMaterias;

    // Tests de base
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp1 = src->createMateria("ice");
    AMateria* tmp2 = src->createMateria("cure");
    me->equip(tmp1);
    me->equip(tmp2);

    // Utilisation des matériaux sur 'bob'
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    // Test du constructeur de copie
    Character alice("alice");
    Character aliceClone(alice);
    aliceClone.equip(src->createMateria("ice"));
    aliceClone.use(0, *me);

    //Test de l'opérateur d'affectation
    Character another("another");
    another = aliceClone;
    another.use(0, *bob);

    // Test de l'équipement et du déséquipement
    alice.equip(src->createMateria("ice"));
    fallenMaterias.push_back(alice.getMateria(0));
    alice.unequip(0);
    alice.use(0, *bob);

    delete bob;
    delete me;
    delete src;

    for (size_t i = 0; i < fallenMaterias.size(); ++i) {
    delete fallenMaterias[i];
    }
    return 0;
}