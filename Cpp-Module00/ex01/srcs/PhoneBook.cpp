/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:47:31 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/31 19:22:43 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <iostream>
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook(void){
	_nb_contacts = 0;
	_index = 0;
}

void	PhoneBook::add_contact(void){
	if(_index == 8)
		_index = 0;
    _contacts[_index++].fill_contact();
	if (_nb_contacts < 8)
		_nb_contacts++;
}

void PhoneBook::search_contact() const {
    if (_nb_contacts == 0) {
        std::cout << "Phone book is empty. No contacts to search." << std::endl;
        return;
    }
    std::cout << "   Index   | First Name | Last Name  | Nickname" << std::endl;
	std::cout << "-----------------------------------------------" << std::endl;
    for (int i = 0; i < _nb_contacts; ++i) {
        _contacts[i].print_search(i);
    }
    int index;
	index = 0;
    std::cout << "Enter index of the contact to view details: ";
    std::cin >> index;
    if (std::cin.fail()) {
        std::cout << "Invalid input. Please enter a valid index." << std::endl;
		std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
    }
    if (index >= 1 && index <= _nb_contacts) {
        _contacts[index - 1].print_contact();
    } else {
        std::cout << "Invalid index." << std::endl;
    }
	std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
