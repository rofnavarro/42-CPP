#pragma once

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					_value;
	static const int	_bits = 8;
public:
						Fixed(void);
						Fixed(const int value);
						Fixed(const float value);
						Fixed(const Fixed &fixed);
						~Fixed(void);
	Fixed				&operator=(const Fixed &rhs);

	int					getRawBits(void) const;
	void				setRawBits(int const raw);

	float				toFloat(void) const;
	int					toInt(void) const;
	
	friend std::ostream	&operator<<(std::ostream &lhs, const Fixed &rhs);
};

#endif