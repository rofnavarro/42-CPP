/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:52:54 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/11 16:28:11 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
:ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name)
:ClapTrap(name)
{
	std::cout << "ScavTrap " << this->_name << " is created" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap)
:ClapTrap(scavTrap)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = scavTrap;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
	return ;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &rhs)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is dead" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " has no energy left" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
	return ;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is dead" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " has no energy left" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " takes " << amount  << " points of damage!" << std::endl;
	this->_energyPoints--;
	this->_hitPoints -= amount;
	return ;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is dead" << std::endl;
		return ;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " has no energy left" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " repairs itself and gets " << amount << " hits points!" << std::endl;
	this->_energyPoints--;
	this->_hitPoints += amount;
	return ;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode" << std::endl;
	return ;
}
