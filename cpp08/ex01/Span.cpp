/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:37:51 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/31 15:20:39 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
:_size(0), _vector()
{
	this->_vector.reserve(0);
	return ;
}

Span::Span(unsigned int N)
:_size(N)
{
	this->_vector.reserve(_size);
	return ;
}

Span::Span(const Span &span)
:_size(span._size), _vector(span._vector)
{
	return ;
}

Span::~Span(void)
{
	return ;
}

Span	&Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		this->_size = rhs._size;
		this->_vector = rhs._vector;
	}
	return (*this);
}

int	&Span::operator[](int index)
{
	if (index < 0 || index >= (int)this->_vector.size())
		throw Span::InvalidIndexException();
	return (this->_vector[index]);
}

void	Span::addNumber(int value)
{
	if (this->_vector.size() == this->_size)
		throw Span::VectorFullException();
	this->_vector.push_back(value);
	return ;
}

int	Span::shortestSpan(void)
{
	std::vector<int>	tmp;
	int	min_span;

	if (this->_vector.size() < 2)
		throw Span::VectorWithOnlyOneValueException();
	tmp = this->_vector;
	std::sort(tmp.begin(), tmp.end());
	min_span = tmp[1] - tmp[0];
	for (unsigned int index = 1; index < tmp.size() - 1; index++)
	{
		if (tmp[index + 1] - tmp[index] < min_span)
			min_span = tmp[index + 1] - tmp[index];
	}
	return (min_span);
}

int	Span::longestSpan(void)
{
	std::vector<int>	tmp;
	int	max_span;

	if (this->_vector.size() < 2)
		throw Span::VectorWithOnlyOneValueException();
	tmp = this->_vector;
	std::sort(tmp.begin(), tmp.end());
	max_span = tmp[tmp.size() - 1] - tmp[0];
	return (max_span);
}

const char	*Span::VectorFullException::what() const throw()
{
	return ("Vector is full!");
}

const char	*Span::VectorWithOnlyOneValueException::what() const throw()
{
	return ("Vector has only one value inside!");
}

const char	*Span::InvalidIndexException::what() const throw()
{
	return ("Vector does not have this index!");
}