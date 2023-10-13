// Dog.hpp
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	Dog(const std::string& type);
	void makeSound() const override;
};

#endif // DOG_HPP
