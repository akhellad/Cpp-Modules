/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:13:07 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/07 10:15:19 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"
#include <iostream>

template <typename T>
void printElement(const T &element) {
    std::cout << element << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::string stringArray[] = {"apple", "banana", "cherry", "date", "fig"};

    iter(intArray, 5, printElement<int>);
    std::cout << std::endl;

    iter(doubleArray, 5, printElement<double>);
    std::cout << std::endl;

    iter(stringArray, 5, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}
