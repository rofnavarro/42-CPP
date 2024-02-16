/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:35:06 by rferrero          #+#    #+#             */
/*   Updated: 2024/02/15 17:49:34 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	a;
	Bureaucrat	*b = new Bureaucrat("carlos", 5);
	Bureaucrat	*c;
	Bureaucrat	*d = new Bureaucrat(a);
	Bureaucrat	*e = new Bureaucrat("andre", -20);

	c = b;

	std::cout << a;
	std::cout << *b;
	std::cout << *c;
	std::cout << *d;

	delete c;
	delete e;
	delete d;

	return (0);
}