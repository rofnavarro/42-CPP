/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:15:25 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/27 20:30:03 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool	isChar(const std::string &input);
static bool	isInt(const std::string &input);
static bool	isFloat(const std::string &input);
static bool	isDouble(const std::string &input);

static bool	intOverflow(const std::string &input);
static bool	floatOverflow(const std::string &input);
static bool	doubleOverflow(const std::string &input);

static void	printChar(char a);
static void	printInt(int i);
static void	printFloat(float f);
static void	printDouble(double d);
static void	printImpossible(std::string type);
static void	printNonDisplayable(void);

static void	charConverter(const std::string &input);
static void	intConverter(const std::string &input);
static void	floatConverter(const std::string &input);
static void	doubleConverter(const std::string &input);

static int	getType(const std::string &input);

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

//	classification

static bool	isChar(const std::string &input)
{
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
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
	if (size > 12)
		return (false);
	return (true);
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
	return (true);
}

static bool	isDouble(const std::string &input)
{
	size_t	size = 0;
	bool	dot = false;

	if (input.compare("nan") == 0 || input.compare("+inf") == 0 || input.compare("-inf") == 0)
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
		if (!std::isdigit(input[size]))
			return (false);
	}
	if (dot == false)
		return (false);
	return (true);
}

//	overflows check

static bool	intOverflow(const std::string &input)
{
	long int	value = std::atol(input.c_str());
	
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		return (true);
	return (false);
}

static bool	floatOverflow(const std::string &input)
{
	double	value = std::strtod(input.c_str(), NULL);
	if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min())
		return (true);
	return (false);
}

static bool	doubleOverflow(const std::string &input)
{
	long double	value = std::strtold(input.c_str(), NULL);
	if (value > std::numeric_limits<double>::max() || value < std::numeric_limits<double>::min())
		return (true);
	return (false);
}

//	print functions

static void	printChar(char a)
{
	std::cout << "char: '" << a << "'" << std::endl;
	return ;
}

static void	printInt(int i)
{
	std::cout << "int: " << i << std::endl;
	return ;
}

static void	printFloat(float f)
{
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	return ;
}

static void	printDouble(double d)
{
	std::cout << "double: " <<std::fixed << std::setprecision(1) << d << std::endl;
	return ;
}

static void	printImpossible(std::string type)
{
	std::cout << type << ": impossible" << std::endl;
	return ;
}

static void	printNonDisplayable(void)
{
	std::cout << "char: non displayable" << std::endl;
	return ;
}

//	converters

static void	charConverter(const std::string &input)
{
	char	c = input[0];

	//	char
	printChar(c);
	//	int
	printInt(static_cast<int>(c));
	//	float
	printFloat(static_cast<float>(c));
	//	double
	printDouble(static_cast<double>(c));
	return ;
}

static void	intConverter(const std::string &input)
{
	long int	i = std::atol(input.c_str());

	//	char
	if (i > 255)
		printImpossible("char");
	else if (i < 32)
		printNonDisplayable();
	else
		printChar(static_cast<char>(i));
	//	int
	if (intOverflow(input) == true)
		printImpossible("int");
	else
		printInt(static_cast<int>(i));
	//	float
	printFloat(static_cast<float>(i));
	//	double
	printDouble(static_cast<double>(i));
	return ;
}

static void	floatConverter(const std::string &input)
{
	double	f = std::strtod(input.c_str(), NULL);

	//	char
	if (input.compare("nanf") == 0 || input.compare("+inff") == 0 || input.compare("-inff") == 0)
		printImpossible("char");
	else if (f > 255)
		printImpossible("char");
	else if (f < 32)
		printNonDisplayable();
	else
		printChar(static_cast<char>(f));
	//	int
	if (input.compare("nanf") == 0 || input.compare("+inff") == 0 || input.compare("-inff") == 0)
		printImpossible("int");
	else if (intOverflow(input) == true)
		printImpossible("int");
	else
		printInt(static_cast<int>(f));
	//	float
	if (input.compare("nanf") == 0 || input.compare("+inff") == 0 || input.compare("-inff") == 0)
		std::cout << "float: " << input << std::endl;
	else if (floatOverflow(input) == true)
		printImpossible("float");
	else
		printFloat(static_cast<float>(f));
	//	double
	printDouble(static_cast<double>(f));
	return ;
}

static void	doubleConverter(const std::string &input)
{
	long double	d = std::strtold(input.c_str(), NULL);

	//	char
	if (input.compare("nan") == 0 || input.compare("+inf") == 0 || input.compare("-inf") == 0)
		printImpossible("char");
	else if (d > 255)
		printImpossible("char");
	else if (d < 32)
		printNonDisplayable();
	else
		printChar(static_cast<char>(d));
	//	int
	if (input.compare("nan") == 0 || input.compare("+inf") == 0 || input.compare("-inf") == 0)
		printImpossible("int");
	else if (intOverflow(input) == true)
		printImpossible("int");
	else
		printInt(static_cast<int>(d));
	//	float
	if (input.compare("nan") == 0 || input.compare("+inf") == 0 || input.compare("-inf") == 0)
		std::cout << "float: " << input + "f" << std::endl;
	else if (floatOverflow(input) == true)
		printImpossible("float");
	else
		printFloat(static_cast<float>(d));
	//	double
	if (doubleOverflow(input) == true)
		printImpossible("double");
	else
		printDouble(static_cast<double>(d));
	return ;
}

//	classification handler

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
	else if (isDouble(input))
		return (DOUBLE);
	return (INVALID);
}

//	mandatory method

void	ScalarConverter::convert(const std::string &input)
{
	int	classification = getType(input);
	
	switch (classification)
	{
	case CHAR:
		charConverter(input);
		break ;
	case INT:
		intConverter(input);
		break ;
	case FLOAT:
		floatConverter(input);
		break ;
	case DOUBLE:
		doubleConverter(input);
		break ;
	default:
		std::cout << "Invalid Input" << std::endl;
		break ;
	}
	return ;
}