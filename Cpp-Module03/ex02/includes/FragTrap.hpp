// FragTrap.hpp
#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap(const std::string& name);
	~FragTrap();

	void attack(const std::string& target) override;
	void highFivesGuys();

	// Vous pouvez ajouter d'autres membres ou méthodes propres à FragTrap ici
};

#endif // FRAGTRAP_HPP
