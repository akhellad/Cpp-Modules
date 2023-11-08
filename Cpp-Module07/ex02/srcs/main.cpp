#include "../includes/Array.hpp"
#include <iostream>

int main() {
    Array<int> intArray(5);
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        intArray[i] = i * 2;
    }

    std::cout << "intArray: ";
    for (unsigned int i = 0; i < intArray.size(); ++i) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    Array<double> doubleArray(3);
    for (unsigned int i = 0; i < doubleArray.size(); ++i) {
        doubleArray[i] = 0.5 * i;
    }

    std::cout << "doubleArray: ";
    for (unsigned int i = 0; i < doubleArray.size(); ++i) {
        std::cout << doubleArray[i] << " ";
    }
    std::cout << std::endl;

    try {
        int invalidIndex = 10;
        std::cout << "Accessing intArray[" << invalidIndex << "]: ";
        intArray[invalidIndex] = 42;
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
