#pragma once

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	Fixed const	_x;
	Fixed const	_y;
public:
				Point(void);
				Point(const float x, const float y);
				Point(Fixed const x, Fixed const y);
				Point(const Point &point);
				~Point(void);

	Point		&operator=(const Point &rhs);

	Fixed const	&getX(void) const;
	Fixed const	&getY(void) const;
};

std::ostream	&operator<<(std::ostream &lhs, Point const &rhs);

#endif