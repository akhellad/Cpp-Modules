/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:39:00 by akhellad          #+#    #+#             */
/*   Updated: 2023/10/31 13:32:56 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"
#include <iostream>


Brain::Brain() {
    for (int i = 0; i < 100; ++i) {
        ideas[i] = "No idea yet";
    }
    std::cout << "Brain constructor called." << std::endl;
}

Brain::Brain(const Brain& other) {
    for (int i = 0; i < 100; ++i) {
        ideas[i] = other.ideas[i];
    }
    std::cout << "Brain copy constructor called." << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            ideas[i] = other.ideas[i];
        }
    }
    std::cout << "Brain assignment operator called." << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called." << std::endl;
}
