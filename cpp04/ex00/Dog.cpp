/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:08:03 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/15 16:39:09 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->_type = "Dog";
	std::cout << "A " << this->_type << " has been born" << std::endl;
	return ;
}

Dog::Dog(const Dog &Dog)
:Animal("Animal Dog")
{
	std::cout << this->_type << " copy constructor called" << std::endl;
	*this = Dog;
	return ;
}

Dog::~Dog(void)
{
	std::cout << this->_type << " has been killed" << std::endl;
	return ;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	std::cout << this->_type << " assignment operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->_type << ": *au*   *au*   *au" << std::endl;
	return ;
}
