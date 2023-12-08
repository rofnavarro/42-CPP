/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:13:59 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/08 14:37:14 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void)
:_x(0), _y(0)
{
	return ;
}

Point::Point(const float x, const float y)
:_x(x), _y(y)
{
	return ;
}

Point::Point(Fixed const x, Fixed const y)
:_x(x), _y(y)
{
	return ;
}

Point::Point(const Point &point)
{
	*this = point;
	return ;
}

Point::~Point(void)
{
	return ;
}

Point	&Point::operator=(const Point &rhs)
{
	if (this != &rhs)
	{
		(void)rhs;
	}
	return (*this);
}


Fixed const &Point::getX(void) const
{
	return (this->_x);
}

Fixed const &Point::getY(void) const
{
	return (this->_y);
}

std::ostream &operator<<(std::ostream &lhs, Point const &point)
{
	lhs << "(" << point.getX() << "," << point.getY() << ")" << std::endl;
	return (lhs);
}
