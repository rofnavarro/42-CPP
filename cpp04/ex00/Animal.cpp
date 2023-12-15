/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:03:23 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/15 15:36:44 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
:_type("Animal")
{
	std::cout << "An " << this->_type << " has been born" << std::endl;
	return ;
}

Animal::Animal(std::string type)
:_type(type)
{
	std::cout << this->_type << " animal has been born" << std::endl;
	return ;
}

Animal::Animal(const Animal &animal)
{
	std::cout << this->_type << " copy constructor called" << std::endl;
	this->_type = animal._type;
	return ;
}

Animal::~Animal(void)
{
	this->_type = "Animal";
	std::cout << this->_type << " has been killed" << std::endl;
	return ;
}

Animal	&Animal::operator=(const Animal &rhs)
{
	std::cout << this->_type << " assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

const std::string	&Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << this->_type << ": *generic animal sound*" << std::endl;
	return ;
}
