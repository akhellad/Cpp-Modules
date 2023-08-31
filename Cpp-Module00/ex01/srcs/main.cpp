/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 18:11:05 by akhellad          #+#    #+#             */
/*   Updated: 2023/08/31 19:19:04 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.h"

int main() {
    PhoneBook phoneBook;
    std::string command;

    do {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            phoneBook.add_contact();
        } else if (command == "SEARCH") {
            phoneBook.search_contact();
        } else if (command != "EXIT") {
            std::cout << "Invalid command. Please try again." << std::endl;
        }
    } while (command != "EXIT");

    return 0;
}