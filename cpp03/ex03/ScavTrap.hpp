#pragma once

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
public:
				ScavTrap(void);
				ScavTrap(std::string name);
				ScavTrap(const ScavTrap &scavTrap);
				~ScavTrap(void);

	ScavTrap	&operator=(const ScavTrap &rhs);

	void		attack(const std::string &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		guardGate(void);
};

#endif