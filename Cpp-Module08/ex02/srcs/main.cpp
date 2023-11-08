#include "../includes/MutantStack.hpp"
#include <list>
#include <iostream>

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "MutantStack contains:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::list<int> l;
    l.push_back(5);
    l.push_back(17);
    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    l.push_back(0);

    std::cout << "std::list contains:" << std::endl;
    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}

