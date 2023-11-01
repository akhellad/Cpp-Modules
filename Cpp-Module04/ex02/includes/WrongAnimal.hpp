// WrongAnimal.hpp
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
public:
	WrongAnimal();
	WrongAnimal(const std::string& type);
	virtual ~WrongAnimal();

	virtual void makeSound() const;
	virtual const std::string& getType() const;

protected:
	std::string type;
};

#endif // WRONGANIMAL_HPP
