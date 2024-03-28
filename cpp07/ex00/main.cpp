/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:26:13 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/28 16:48:26 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int	main(void)
{
	char	x;
	char	y;

	x = 'a';
	y = 'c';

	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;
	std::cout << "min: " << ::min(x, y) << std::endl;
	std::cout << "max: " << ::max(x, y) << std::endl;


	::swap(x, y);

	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;
	std::cout << "min: " << ::min(x, y) << std::endl;
	std::cout << "max: " << ::max(x, y) << std::endl;

	int	a;
	int	b;

	a = 9;
	b = 1;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "min: " << ::min(a, b) << std::endl;
	std::cout << "max: " << ::max(a, b) << std::endl;


	::swap(a, b);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "min: " << ::min(a, b) << std::endl;
	std::cout << "max: " << ::max(a, b) << std::endl;

	return (0);
}