/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:19:11 by akhellad          #+#    #+#             */
/*   Updated: 2024/01/17 14:18:52 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/span.hpp"
#include <iostream>

void printSpan(const Span& sp) {
    const std::vector<int>& numbers = sp.getNumbers();
    std::cout << "Span contains: ";
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i];
        if (i < numbers.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

int main() {
    Span sp = Span(30);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    printSpan(sp);
    try {
        int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
        sp.addRange(values, values + 11);
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    printSpan(sp);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;


    Span span = Span(5);
    span.addNumber(6);
    span.addNumber(3);
    span.addNumber(17);
    span.addNumber(9);
    span.addNumber(11);
    std::cout << span.shortestSpan() << std::endl;
    std::cout << span.longestSpan() << std::endl;

    return 0;
}
