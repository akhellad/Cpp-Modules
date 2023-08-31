/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:43:18 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/31 19:16:19 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

Contact::Contact(void) {}

void	Contact::fill_contact(void){
	std::cout << "Enter first name: ";
	std::getline(std::cin, _first_name);
	std::cout << "Enter last name: ";
	std::getline(std::cin, _last_name);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, _nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, _phone_number);
	std::cout << "Enter Darkest secret: ";
	std::getline(std::cin, _darkest_secret);
}

void	Contact::print_contact(void) const{
	std::cout << "First name : " << _first_name << std::endl;
	std::cout << "Last name : " << _last_name << std::endl;
	std::cout << "Nickname : " << _nickname << std::endl;
	std::cout << "Phone number : " << _phone_number << std::endl;
	std::cout << "Darkest Secret : " << _darkest_secret << std::endl;
}

void Contact::print_search(int index) const {
    std::cout << std::setw(10) << index + 1 << " | ";
    std::cout << std::setw(10) << std::right << truncateString(_first_name, 10) << " | ";
    std::cout << std::setw(10) << std::right << truncateString(_last_name, 10) << " | ";
    std::cout << std::setw(10) << std::right << truncateString(_nickname, 10) << std::endl;
}

std::string truncateString(const std::string& str, size_t width) {
    if (str.length() > width) {
        return str.substr(0, width - 1) + ".";
    } else {
        return str;
    }
}