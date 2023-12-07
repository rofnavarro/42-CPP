/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:46:58 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/07 17:58:24 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	// std::cout << "Default contructor called" << std::endl;
	this->_value = 0;
	return ;
}

Fixed::Fixed(const int value)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_value = value << this->_bits;
	return ;
}

Fixed::Fixed(const float value)
{
	// std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(value * (1 << this->_bits));
	return ;
}

Fixed::Fixed(const Fixed &fixed)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
	return ;
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" <<std::endl;
	return ;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	if (this != &rhs)
	{
		// std::cout << "Copy assignment operator called" << std::endl;
		this->_value = rhs.getRawBits();
	}
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	float	lhs;

	lhs = this->toFloat() + rhs.toFloat();
	return (Fixed(lhs));
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	float	lhs;

	lhs = this->toFloat() - rhs.toFloat();
	return (Fixed(lhs));
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	float	lhs;

	lhs = this->toFloat() * rhs.toFloat();
	return (Fixed(lhs));
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	float	lhs;

	lhs = this->toFloat() / rhs.toFloat();
	return (Fixed(lhs));
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->_value > rhs._value);
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->_value < rhs._value);
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_value >= rhs._value);
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_value <= rhs._value);
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->_value == rhs._value);
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_value != rhs._value);
}

Fixed	Fixed::operator++(int)
{
	Fixed lhs(*this);

	++this->_value;
	return (lhs);
}

Fixed	Fixed::operator--(int)
{
	Fixed lhs(*this);

	--this->_value;
	return (lhs);
}

Fixed	&Fixed::operator++(void)
{
	++this->_value;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	--this->_value;
	return (*this);
}

Fixed &Fixed::min(Fixed &fix1, Fixed &fix2)
{
	if (fix1 <= fix2)
		return (fix1);
	return (fix2);
}

const Fixed	&Fixed::min(const Fixed &fix1, const Fixed &fix2)
{
	if (fix1 <= fix2)
		return (fix1);
	return (fix2);
}

Fixed	&Fixed::max(Fixed &fix1, Fixed &fix2)
{
	if (fix1 >= fix2)
		return (fix1);
	return (fix2);
}

const Fixed	&Fixed::max(const Fixed &fix1, const Fixed &fix2)
{
	if (fix1 >= fix2)
		return (fix1);
	return (fix2);
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	float	_float;

	_float = float((float)(this->_value) / (float)(1 << this->_bits));
	return (_float);
}

int	Fixed::toInt(void) const
{
	int	_int;

	_int = this->_value >> _bits;
	return (_int);
}

std::ostream	&operator<<(std::ostream &lhs, const Fixed &rhs)
{
	lhs << rhs.toFloat();
	return (lhs);
}
