#pragma once

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <cstdlib>
# include <iostream>
# include <limits>
# include <cmath>
# include <iomanip>

# include <cstdio>

typedef enum	e_class
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	INVALID,
}	t_class;

class	ScalarConverter
{
private:
					ScalarConverter(void);
					ScalarConverter(const ScalarConverter &scalarconverter);
					~ScalarConverter(void);

	ScalarConverter	&operator=(const ScalarConverter &rhs);
	
public:
	static void		convert(const std::string &input);
};

#endif