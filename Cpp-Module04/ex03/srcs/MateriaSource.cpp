/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:27:18 by akhellad          #+#    #+#             */
/*   Updated: 2023/12/01 15:25:39 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++) {
        sources[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    copySources(other);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        clearSources();
        copySources(other);
    }
    return *this;
}

MateriaSource::~MateriaSource() {
    clearSources();
}

void MateriaSource::clearSources() {
    for (int i = 0; i < 4; i++) {
        delete sources[i];
        sources[i] = NULL;
    }
}

void MateriaSource::copySources(const MateriaSource& other) {
    for (int i = 0; i < 4; i++) {
        if (other.sources[i])
            sources[i] = other.sources[i]->clone();
        else
            sources[i] = NULL;
    }
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (sources[i] == NULL) {
            sources[i] = m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; i++) {
        if (sources[i] != NULL && sources[i]->getType() == type) {
            return sources[i]->clone();
        }
    }
    return NULL;
}
