// Cat.cpp
#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "A Cat is born!" << std::endl;
}

Cat::Cat(const std::string& type) : Animal(type) {
	std::cout << "A " << type << " is born!" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}
