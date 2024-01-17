/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:53:42 by akhellad          #+#    #+#             */
/*   Updated: 2023/12/01 15:53:43 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Generic Animal") {
	std::cout << "A wrong animal is born!" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& t) : type(t) {
	std::cout << "A wrong " << type << " is born!" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "The wrong " << type << " is destroyed!" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "Wrong Animal sound" << std::endl;
}

const std::string& WrongAnimal::getType() const {
	return type;
}
