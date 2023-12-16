/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:53:49 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/16 15:36:54 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->_type = "Cat";
	std::cout << "A " << this->_type << " has been born" << std::endl;
	this->_brain = new Brain();
	return ;
}

Cat::Cat(const Cat &cat)
:AAnimal()
{
	std::cout << this->_type << " copy constructor called" << std::endl;
	*this = cat;
	return ;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << this->_type << " has been killed" << std::endl;
	return ;
}

Cat	&Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
	{
		delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
		this->_type = rhs._type;
	}
	std::cout << this->_type << " assignment operator called" << std::endl;
	return (*this);
}

const std::string	&Cat::getType(void) const
{
	return (this->_type);
}

const std::string	&Cat::getIdea(const int index) const
{
	return (this->_brain->getIdea(index));
}

void	Cat::setIdea(const std::string &idea)
{
	this->_brain->setIdea(idea);
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << this->_type << ": *miaw*   *miaw*   *miaw" << std::endl;
	return ;
}
