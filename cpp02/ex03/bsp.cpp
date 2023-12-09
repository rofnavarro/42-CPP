/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:06:31 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/09 01:08:35 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

double	pointsDistance(Point const &one, Point const &two)
{
	double	dist;

	dist = sqrt(pow((one.getX()).toFloat() - (two.getX()).toFloat(), 2) + pow((one.getY()).toFloat() - (two.getY()).toFloat(), 2));
	
	return (dist);
}

bool	isTriangle(Point a, Point b, Point c)
{
	double	x;
	double	y;
	double	z;

	x = pointsDistance(a, b);
	y = pointsDistance(b, c);
	z = pointsDistance(c, a);
	if (fabs(y - z) < x && x < (y + z))
	{
		if (fabs(x - z) < y && y < (x + z))
		{
			if (fabs(x - y) < z && z < (x + y))
				return (true);
		}
	}
	return (false);
}

float	triangleArea(Point const &a, Point const &b, Point const &c)
{
	float	semiPerimeter;
	float	area;

	semiPerimeter = (pointsDistance(a, b) + pointsDistance(b, c) + pointsDistance(c, a)) / 2;

	area = sqrt(semiPerimeter * (semiPerimeter - pointsDistance(a, b)) * (semiPerimeter - pointsDistance(b, c)) * (semiPerimeter - pointsDistance(c, a)));

	if (area >= 0)
		return (area);
	else
		return (area * -1);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool	ret;
	float	area[4];

	area[0] = triangleArea(a, b, c);
	area[1] = triangleArea(point, b, c);
	area[2] = triangleArea(a, point, c);
	area[3] = triangleArea(a, b, point);

	std::cout << "Area ABC: " << area[0] << std::endl;
	std::cout << "Area PBC: " << area[1] << std::endl;
	std::cout << "Area PCA: " << area[2] << std::endl;
	std::cout << "Area PAB: " << area[3] << std::endl;

	if ( (area[0]) == (area[1] + area[2] + area[3]))
		ret = true;
	else
		ret = false;
	return (ret);
}