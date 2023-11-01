// WrongCat.cpp
#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "A WrongCat is born!" << std::endl;
}

WrongCat::WrongCat(const std::string& type) : WrongAnimal(type) {
	std::cout << "A " << type << " is born!" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongMeow! WrongMeow!" << std::endl;
}