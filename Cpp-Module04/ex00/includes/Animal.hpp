// Animal.hpp
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
public:
	Animal();
	Animal(const std::string& type);
	virtual ~Animal();

	virtual void makeSound() const = 0;
	virtual const std::string& getType() const;

protected:
	std::string type;
};

#endif // ANIMAL_HPP
