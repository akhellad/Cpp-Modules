/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 19:34:08 by akhellad          #+#    #+#             */
/*   Updated: 2023/12/18 15:59:47 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat b("John", 10);
        Bureaucrat c("bob", 50);
        std::cout << b << std::endl;
        std::cout << c << std::endl;
        c.incrementGrade();
        b.incrementGrade();
        std::cout << b << std::endl;
        std::cout << c << std::endl;
        b.decrementGrade();
        c.decrementGrade();
        std::cout << b << std::endl;
        std::cout << c << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
