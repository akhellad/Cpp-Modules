/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:34:08 by akhellad          #+#    #+#             */
/*   Updated: 2023/10/31 20:37:29 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat john("John", 1);
        Bureaucrat mary("Mary", 150);

        Form taxForm("Tax Form", 100, 50);

        std::cout << john << std::endl;
        std::cout << mary << std::endl;
        std::cout << taxForm << std::endl;

        john.signForm(taxForm);
        std::cout << taxForm << std::endl;

        mary.signForm(taxForm);

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
