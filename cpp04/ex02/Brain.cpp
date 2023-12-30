/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:30:23 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/30 12:07:57 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
:_counter(0)
{
	std::cout << "A Brain has been developed" << std::endl;
	return ;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "A Brain has been copied from another Brain" << std::endl;
	*this = brain;
	return ;
}

Brain::~Brain(void)
{
	std::cout << "Brain meltdown" << std::endl;
	return ;
}

Brain	&Brain::operator=(const Brain &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < rhs._counter; i++)
			this->_ideas[i] = rhs._ideas[i];
		this->_counter = rhs._counter;
	}
	std::cout << "The ideas of a Brain has been assigned to another Brain" << std::endl;
	return (*this);
}

const std::string	&Brain::getIdea(const int index) const
{
	if (index > this->_counter)
		return (this->_ideas[this->_counter]);
	return (this->_ideas[index]);
}

void	Brain::setIdea(const std::string &idea)
{
	if (this->_counter >= 100)
		std::cout << "This Brain is already full of ideas!" <<std::endl;
	else
	{
		this->_ideas[this->_counter] = idea;
		this->_counter++;
	}
	return ;
}

