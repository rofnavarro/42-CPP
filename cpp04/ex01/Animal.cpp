/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:03:23 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/16 11:03:45 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
:_type("Animal")
{
	std::cout << "An " << this->_type << " has been born" << std::endl;
	return ;
}

Animal::Animal(const Animal &animal)
{
	*this = animal;
	std::cout << this->_type << " copy constructor called" << std::endl;
	return ;
}

Animal::~Animal(void)
{
	if (this->_type != "Animal")
		this->_type = "Animal " + this->_type;
	std::cout << this->_type << " has been killed" << std::endl;
	return ;
}

Animal	&Animal::operator=(const Animal &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	std::cout << this->_type << " assignment operator called" << std::endl;
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
