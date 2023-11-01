// WrongCat.hpp
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	WrongCat(const std::string& type);
	void makeSound() const ;
};

#endif // WRONGCAT_HPP