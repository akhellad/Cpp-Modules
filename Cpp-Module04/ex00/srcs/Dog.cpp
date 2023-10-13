// Dog.cpp
#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "A Dog is born!" << std::endl;
}

Dog::Dog(const std::string& type) : Animal(type) {
	std::cout << "A " << type << " is born!" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}
