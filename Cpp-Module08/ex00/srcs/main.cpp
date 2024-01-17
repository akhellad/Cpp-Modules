/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:59:58 by akhellad          #+#    #+#             */
/*   Updated: 2024/01/17 13:21:10 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main() {
    int array[] = {1, 2, 3, 4, 5};
    std::vector<int> vector(array, array + sizeof(array) / sizeof(array[0]));
    std::list<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);

    try {
        int valueToFind = 4;
        std::vector<int>::iterator vectorResult = easyfind(vector, valueToFind);
        std::cout << "Value " << valueToFind << " found in vector at position " << std::distance(vector.begin(), vectorResult) << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        int valueToFind = 40;
        std::list<int>::iterator listResult = easyfind(list, valueToFind);
        std::cout << "Value " << valueToFind << " found in list at position " << std::distance(list.begin(), listResult) << std::endl;
    } catch (const std::runtime_error &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
