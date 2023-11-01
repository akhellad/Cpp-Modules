// ScavTrap.hpp
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp" // Assurez-vous d'inclure le fichier d'en-tête de ClapTrap

class ScavTrap : public ClapTrap {
public:
	ScavTrap(const std::string& name);
	~ScavTrap();

	void attack(const std::string& target) ;
	void guardGate(); // La capacité spéciale

	// Vous pouvez ajouter d'autres membres ou méthodes propres à ScavTrap ici
};

#endif // SCAVTRAP_HPP

