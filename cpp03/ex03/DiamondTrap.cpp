/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:43:46 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/13 12:59:11 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
:ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->_name = "DiamondTrap";
	this->ClapTrap::_name = this->ClapTrap::getName() + "_clap_name";
	this->_hitPoints = this->FragTrap::getHitPoints();
	this->_energyPoints =  this->ScavTrap::getEnergyPoints();
	this->_attackDamage = this->FragTrap::getAttackDamage();
	return ;
}

DiamondTrap::DiamondTrap(std::string name)
:ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->ClapTrap::_name = this->_name + "_clap_name";
	std::cout << "DiamondTrap " << this->_name << " is created" << std::endl;
	this->_hitPoints = FragTrap::getHitPoints();
	this->_energyPoints =  ScavTrap::getEnergyPoints();
	this->_attackDamage = FragTrap::getAttackDamage();
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap)
:ClapTrap(diamondTrap), ScavTrap(diamondTrap), FragTrap(diamondTrap)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = diamondTrap;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
	return ;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &rhs)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->ClapTrap::_name = this->_name + "_clap_name";
		this->_hitPoints = rhs.FragTrap::_hitPoints;
		this->_energyPoints = rhs.ScavTrap::_energyPoints;
		this->_attackDamage = rhs.FragTrap::_attackDamage;
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string &target)
{
	this->ScavTrap::attack(target);
	return ;
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is dead" << std::endl;
		return ;
	}
	std::cout << "DiamondTrap " << this->_name << " takes " << amount  << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
	return ;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is dead" << std::endl;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " has no energy left" << std::endl;
	}
	if (this->_energyPoints > 0)
	{
		std::cout << "DiamondTrap " << this->_name << " repairs itself and gets " << amount << " hits points!" << std::endl;
		this->_energyPoints--;
		this->_hitPoints += amount;
	}
	return ;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << this->ClapTrap::_name << std::endl;
	return ;
}

