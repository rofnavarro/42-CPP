#pragma once

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	_name;
public:
				DiamondTrap(void);
				DiamondTrap(std::string name);
				DiamondTrap(const DiamondTrap &diamondTrap);
				~DiamondTrap(void);

	DiamondTrap	&operator=(const DiamondTrap &rhs);

	void		attack(const std::string &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		whoAmI(void);
};

#endif