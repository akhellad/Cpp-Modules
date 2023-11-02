/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhellad <akhellad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:28:34 by akhellad          #+#    #+#             */
/*   Updated: 2023/11/02 13:48:09 by akhellad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

enum class ObjectType { A, B, C };

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

ObjectType identifyObjectType(Base* p) {
    if (dynamic_cast<A*>(p)) {
        return ObjectType::A;
    } else if (dynamic_cast<B*>(p)) {
        return ObjectType::B;
    } else if (dynamic_cast<C*>(p)) {
        return ObjectType::C;
    }
    return ObjectType::A;
}

void identify(Base* p) {
    ObjectType type = identifyObjectType(p);

    switch (type) {
        case ObjectType::A:
            std::cout << "A" << std::endl;
            break;
        case ObjectType::B:
            std::cout << "B" << std::endl;
            break;
        case ObjectType::C:
            std::cout << "C" << std::endl;
            break;
    }
}

void identify(Base& p) {
    ObjectType type = identifyObjectType(&p);

    switch (type) {
        case ObjectType::A:
            std::cout << "A" << std::endl;
            break;
        case ObjectType::B:
            std::cout << "B" << std::endl;
            break;
        case ObjectType::C:
            std::cout << "C" << std::endl;
            break;
    }
}

int main() {
    srand(time(NULL));

    Base* base = generate();

    identify(base);
    identify(*base);

    delete base;
    return 0;
}