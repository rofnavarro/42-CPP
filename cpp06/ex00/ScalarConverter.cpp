/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:15:25 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/27 15:10:19 by rferrero         ###   ########.fr       */
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
	long int	value = std::atol(input.c_str());
	
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

static bool	floatOverflow(const std::string &input)
{
	double	value = std::strtod(input.c_str(), NULL);
	if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min())
		return (true);
	return (false);
}

static bool	isFloat(const std::string &input)
{
	size_t	size = 0;
	bool	dot = false;

	if (input.compare("nanf") == 0 || input.compare("+inff") == 0 || input.compare("-inff") == 0)
		return (true);
	for (; size < input.length(); size++)
	{
		if (input[size] == '-' && size == 0)
			continue ;
		if (input[size] == '.')
		{
			if (dot == true)
				return (false);
			dot = true;
			continue ;
		}
		if (input[size] == 'f')
		{
			if (size != input.length() - 1)
				return (false);
			continue ;
		}
		if (!std::isdigit(input[size]) || input[input.length() - 1] != 'f')
			return (false);
	}
	if (dot == false)
		return (false);
	if (floatOverflow(input) == true)
		return (false);
	return (true);
}

static int	getType(const std::string &input)
{
	if (input.empty())
		return (INVALID);
	else if (isChar(input))
		return (CHAR);
	else if (isInt(input))
		return(INT);
	else if (isFloat(input))
		return (FLOAT);
	return (INVALID);
}

void	ScalarConverter::convert(const std::string &input)
{
	int	classification = getType(input);
	
	std::cout << classification << std::endl;
	return ;
}