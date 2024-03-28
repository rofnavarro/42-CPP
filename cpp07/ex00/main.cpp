/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:26:13 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/28 16:52:08 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

// int	main(void)
// {
// 	char	x;
// 	char	y;

// 	x = 'a';
// 	y = 'c';

// 	std::cout << "x = " << x << std::endl;
// 	std::cout << "y = " << y << std::endl;
// 	std::cout << "min: " << ::min(x, y) << std::endl;
// 	std::cout << "max: " << ::max(x, y) << std::endl;


// 	::swap(x, y);

// 	std::cout << "x = " << x << std::endl;
// 	std::cout << "y = " << y << std::endl;
// 	std::cout << "min: " << ::min(x, y) << std::endl;
// 	std::cout << "max: " << ::max(x, y) << std::endl;

// 	int	a;
// 	int	b;

// 	a = 9;
// 	b = 1;

// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "b = " << b << std::endl;
// 	std::cout << "min: " << ::min(a, b) << std::endl;
// 	std::cout << "max: " << ::max(a, b) << std::endl;


// 	::swap(a, b);

// 	std::cout << "a = " << a << std::endl;
// 	std::cout << "b = " << b << std::endl;
// 	std::cout << "min: " << ::min(a, b) << std::endl;
// 	std::cout << "max: " << ::max(a, b) << std::endl;

// 	return (0);
// }

int main( void )
{
	int a = 2;
	int b = 3;

	::swap( a, b );

	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min( a, b ) << std::endl;
	std::cout << "max(a, b) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min( c, d ) << std::endl;
	std::cout << "max(c, d) = " << ::max( c, d ) << std::endl;
	
	return (0);
}