// Animal.cpp
#include "../includes/Animal.hpp"

Animal::Animal() : type("Generic Animal") {
	std::cout << "An animal is born!" << std::endl;
}

Animal::Animal(const std::string& t) : type(t) {
	std::cout << "A " << type << " is born!" << std::endl;
}

Animal::~Animal() {
	std::cout << "The " << type << " is destroyed!" << std::endl;
}

const std::string& Animal::getType() const {
	return type;
}