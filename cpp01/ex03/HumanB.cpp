/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:53:07 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/01 20:14:17 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
:_name(name)
{
	this->_weapon = NULL;
	return ;
}

HumanB::~HumanB(void)
{
	return ;
}

void	HumanB::setName(std::string name)
{
	this->_name = name;
	return ;
}

const std::string	&HumanB::getName(void) const
{
	return (this->_name);
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	return ;
}

const Weapon	&HumanB::getWeapon(void) const
{
	return (*this->_weapon);
}

void	HumanB::attack(void)
{
	if (this->_weapon == NULL)
		std::cout << this->_name << "do not have any weapons" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	return ;
}
