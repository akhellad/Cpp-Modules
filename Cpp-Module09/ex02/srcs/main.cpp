/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:09:33 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/09 11:26:34 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include "../includes/PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [list of positive integers]" << std::endl;
        return 1;
    }

    std::vector<int> numbersVec;
    std::list<int> numbersList;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        try {
            int number = std::atoi(arg.c_str());
            if (number < 0) {
                throw std::invalid_argument("Negative number");
            }
            numbersVec.push_back(number);
            numbersList.push_back(number);
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << " for argument \"" << arg << "\"" << std::endl;
            return 1;
        }
    }

    PmergeMe pmergeMe;
    pmergeMe.displayResult(numbersVec, numbersList);

    return 0;
}
