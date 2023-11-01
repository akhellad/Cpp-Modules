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

	std::cout << wrongI->getType() << " " << std::endl;
	wrongI->makeSound();

	delete j;
	delete i;
	delete wrongI;

	return 0;
}

