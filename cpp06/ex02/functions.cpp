/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:55:44 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/28 00:05:46 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

Base	*generate(void)
{
	std::srand(std::time(0));

	int	i = std::rand() % 3;
	if (i == 0)
		return (new A);
	else if (i == 1)
		return (new B);
	else if (i == 2)
		return (new C);
	return (NULL);
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "Pointer type A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "Pointer type B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "Pointer type C" << std::endl;
	else
		std::cout << "Invalid Base Pointer" << std::endl;
	return ;
}

void	identify(Base &p)
{
	try
	{
		A	&a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Reference type A" << std::endl;
		return ;
	}
	catch(...){}
	try
	{
		B	&b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Reference type B" << std::endl;
		return ;
	}
	catch(...){}
	try
	{
		C	&c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Reference type C" << std::endl;
		return ;
	}
	catch(...){}
	std::cout << "Invalid Base Reference" << std::endl;
	return ;
}