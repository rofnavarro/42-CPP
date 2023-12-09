#pragma once

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
private:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

public:
				ClapTrap(void);
				ClapTrap(std::string name);
				ClapTrap(const ClapTrap &clapTrap);
				~ClapTrap(void);

	ClapTrap	&operator=(const ClapTrap &rhs);

	void		attack(const std::string &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};

#endif