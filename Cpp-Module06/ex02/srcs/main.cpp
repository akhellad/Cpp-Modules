/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:28:34 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/07 09:42:21 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

Base* generate() {
    std::srand(std::time(0));
    int randomValue = std::rand() % 3;

    switch (randomValue) {
        case 0: return new A;
        case 1: return new B;
        case 2: return new C;
        default: return NULL;
    }
}

void identifyObjectType(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    }
}

void identify(Base& p) {
    try
    {
        Base x = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
    }
    catch(std::exception& e){}
    try
    {
        Base x = dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
    }
    catch(std::exception& e){}
    try
    {
        Base x = dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
    }
    catch(std::exception& e){}
}

int main() {
    srand(time(NULL));

    Base* base = generate();

    identifyObjectType(base);
    identify(*base);

    delete base;
    return 0;
}