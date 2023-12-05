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

	Fixed				operator>(const Fixed &rhs) const;
	Fixed				operator<(const Fixed &rhs) const;
	Fixed				operator>=(const Fixed &rhs) const;
	Fixed				operator<=(const Fixed &rhs) const;
	Fixed				operator==(const Fixed &rhs) const;
	Fixed				operator!=(const Fixed &rhs) const;

	Fixed				operator+(const Fixed &rhs) const;
	Fixed				operator-(const Fixed &rhs) const;
	Fixed				operator*(const Fixed &rhs) const;
	Fixed				operator/(const Fixed &rhs) const;

	Fixed				operator++(void);
	Fixed				operator--(void);

	Fixed				&operator++(void);
	Fixed				&operator--(void);

	static Fixed		&min(Fixed &fix1, Fixed &fix2);
	static const Fixed	&min(const Fixed &fix1, const Fixed &fix2);

	static Fixed		&max(Fixed &fix1, Fixed &fix2);
	static const Fixed	&max(const Fixed &fix1, const Fixed &fix2);

	int					getRawBits(void) const;
	void				setRawBits(int const raw);

	float				toFloat(void) const;
	int					toInt(void) const;
	
	friend std::ostream	&operator<<(std::ostream &lhs, const Fixed &rhs);
};

#endif