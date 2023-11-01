#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
public:
	ClapTrap(const std::string& name);
	~ClapTrap();

	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	int getHitPoints() const;

protected: 
	std::string name;
	int hitPoints;
	int energyPoints;
	int attackDamage;
};

#endif // CLAPTRAP_HPP

