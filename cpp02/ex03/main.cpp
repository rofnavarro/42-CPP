/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:05:31 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/08 16:09:30 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	isTriangle(Point a, Point b, Point c);
bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	std::string x;
	std::string y;
	float	a[2];
	float	b[2];
	float	c[2];
	float	p[2];

	std::cout << "Please enter three points to make a triangle" << std::endl;

	std::cout << "First number x: ";
	std::getline(std::cin, x);
	std::cout << "First number y: ";
	std::getline(std::cin, y);
	a[0] = (atof(x.c_str()));
	a[1] = (atof(y.c_str()));

	std::cout << "Second number x: ";
	std::getline(std::cin, x);
	std::cout << "Second number y: ";
	std::getline(std::cin, y);
	b[0] = (atof(x.c_str()));
	b[1] = (atof(y.c_str()));

	std::cout << "Third number x: ";
	std::getline(std::cin, x);
	std::cout << "Third number y: ";
	std::getline(std::cin, y);
	c[0] = (atof(x.c_str()));
	c[1] = (atof(y.c_str()));

	if (isTriangle(Point(a[0],a[1]), Point(b[0],b[1]), Point(c[0],c[1])) == false)
	{
		std::cout << "Those points do not make a triangle" << std::endl;
		return (1);
	}

	std::cout << "Insert a point to check if it's inside the triangle" << std::endl;
	std::cout << "Point x: ";
	std::getline(std::cin, x);
	std::cout << "Point y: ";
	std::getline(std::cin, y);
	p[0] = (atof(x.c_str()));
	p[1] = (atof(y.c_str()));

	if (bsp(Point(a[0],a[1]), Point(b[0],b[1]), Point(c[0],c[1]), Point(p[0], p[1])) == true)
		std::cout << "The point is inside the triangle" << std::endl;
	else
		std::cout << "The point is NOT inside the triangle" << std::endl;

	return (0);
}
