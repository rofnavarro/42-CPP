/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:03:23 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/16 11:03:45 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
:_type("AAnimal")
{
	std::cout << this->_type << " has been born" << std::endl;
	return ;
}

AAnimal::AAnimal(const AAnimal &aAnimal)
{
	*this = aAnimal;
	std::cout << this->_type << " copy constructor called" << std::endl;
	return ;
}

AAnimal::~AAnimal(void)
{
	std::cout << this->_type << " has been killed" << std::endl;
	return ;
}

AAnimal	&AAnimal::operator=(const AAnimal &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	std::cout << this->_type << " assignment operator called" << std::endl;
	return (*this);
}

const std::string	&AAnimal::getType(void) const
{
	return (this->_type);
}
