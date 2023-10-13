#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	Cat(const std::string& type);
	void makeSound() const override;
};

#endif // CAT_HPP
