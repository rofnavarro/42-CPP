/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:43:32 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/11 18:18:39 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void)
:ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name)
:ClapTrap(name)
{
	std::cout << "FragTrap " << this->_name << " is created" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return ;
}

FragTrap::FragTrap(const FragTrap &fragTrap)
:ClapTrap(fragTrap)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = fragTrap;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
	return ;
}

FragTrap	&FragTrap::operator=(const FragTrap &rhs)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void	FragTrap::attack(const std::string &target)
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
	{	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	return ;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is dead" << std::endl;
	}
	else
	{
		std::cout << "FragTrap " << this->_name << " takes " << amount  << " points of damage!" << std::endl;
		this->_hitPoints -= amount;
	}
	return ;
}

void	FragTrap::beRepaired(unsigned int amount)
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
		std::cout << "FragTrap " << this->_name << " repairs itself and gets " << amount << " hits points!" << std::endl;
		this->_energyPoints--;
		this->_hitPoints += amount;
	}
	return ;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << this->_name << " is requesting a high five!!" << std::endl;
	return ;
}
