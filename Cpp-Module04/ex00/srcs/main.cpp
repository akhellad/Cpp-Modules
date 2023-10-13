#include "../includes/Animal.hpp"
#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongAnimal.hpp"
#include "../includes/WrongCat.hpp"
#include <iostream>

int main() {
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrongI = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std:: cout << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound();

	// WrongAnimal et WrongCat
	std::cout << wrongI->getType() << " " << std::endl;
	wrongI->makeSound();

	// Assurez-vous de libérer la mémoire allouée dynamiquement
	delete j;
	delete i;
	delete wrongI;

	return 0;
}

