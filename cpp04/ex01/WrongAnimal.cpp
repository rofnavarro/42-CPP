/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:14:43 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/16 11:07:56 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
:_type("Wrong Animal")
{
	std::cout << "A " << this->_type << " has been born" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
	*this = wrongAnimal;
	std::cout << this->_type << " copy constructor called" << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal(void)
{
	if (this->_type != "Wrong Animal")
		this->_type = this->_type + " Animal (WrongAnimal)";
	std::cout << this->_type << " has been killed" << std::endl;
	return ;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	std::cout << this->_type << " assignment operator called" << std::endl;
	return (*this);
}

const std::string	&WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << this->_type << ": *very weird animal sound*" << std::endl;
	return ;
}
