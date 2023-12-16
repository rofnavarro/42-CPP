/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 19:25:55 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/15 19:29:37 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->_type = "Wrong Cat";
	std::cout << "A " << this->_type << " has been born" << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat &wrongCat)
:WrongAnimal()
{
	*this = wrongCat;
	std::cout << this->_type << " copy constructor called" << std::endl;
	return ;
}

WrongCat::~WrongCat(void)
{
	std::cout << this->_type << " has been killed" << std::endl;
	return ;
}
WrongCat	&WrongCat::operator=(const WrongCat &rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	std::cout << this->_type << " assignment operator called" << std::endl;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << this->_type << ": *meowf*   *meowf*   *meowf" << std::endl;
	return ;
}

