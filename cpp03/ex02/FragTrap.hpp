#pragma once

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap :  public ClapTrap
{
public:
				FragTrap(void);
				FragTrap(std::string name);
				FragTrap(const FragTrap &fragtrap);
				~FragTrap(void);

	FragTrap	&operator=(const FragTrap &rhs);

	void		attack(const std::string &target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	void		highFiveGuys(void);
};

#endif