/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:15:25 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/27 13:49:54 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
	std::cout << "Default ScalarConverter constructor called." << std::endl;
	return ;
}

ScalarConverter::ScalarConverter(const ScalarConverter &scalarconverter)
{
	std::cout << "ScalarConverter copy constructor called." << std::endl;
	*this = scalarconverter;
	return ;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter destructor called." << std::endl;
	return ;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &rhs)
{
	std::cout << "ScalarConverter assignment operator called." << std::endl;
	(void)rhs;
	return (*this);
}

static bool	isChar(const std::string &input)
{
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
		return (true);
	return (false);
}

static bool	intOverflow(const std::string &input)
{
	long int	value;

	value = std::atol(input.c_str());
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		return (true);
	return (false);
}

static bool	isInt(const std::string &input)
{
	size_t size = 0;

	for (; size < input.length(); size++)
	{
		if (input[size] == '-' && size == 0)
			continue ;		
		if (!std::isdigit(input[size]))
			return (false);
	}
	if (size >= 10 && intOverflow(input) == true)
		return (false);
	return (true);
}

static int	getType(const std::string &input)
{
	if (input.empty())
		return (INVALID);
	if (isChar(input))
		return (CHAR);
	if (isInt(input))
		return(INT);
	return (INVALID);
}

void	ScalarConverter::convert(const std::string &input)
{
	int	classification;

	classification = getType(input);
	std::cout << classification << std::endl;
	return ;
}