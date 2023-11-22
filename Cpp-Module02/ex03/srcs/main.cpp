/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:17:38 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/22 11:17:39 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Point.hpp"
#include "../includes/bsp.hpp"

int main() {
    Point a(0.0f, 0.0f);
    Point b(4.0f, 0.0f);
    Point c(0.0f, 3.0f);
    Point p1(2.0f, 1.5f);
    Point p2(5.0f, 5.0f);
    Point p3(0.0f, 0.0f);

    std::cout << "p1 is inside triangle: " << bsp(a, b, c, p1) << std::endl; // Devrait afficher true
    std::cout << "p2 is inside triangle: " << bsp(a, b, c, p2) << std::endl; // Devrait afficher false
    std::cout << "p3 is inside triangle: " << bsp(a, b, c, p3) << std::endl; // Devrait afficher false

    return 0;
}
