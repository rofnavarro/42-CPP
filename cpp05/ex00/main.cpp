/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:35:06 by rferrero          #+#    #+#             */
/*   Updated: 2024/02/12 22:21:40 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	a;
	Bureaucrat	*b = new Bureaucrat("carlos", 5);
	Bureaucrat	*c;
	Bureaucrat	*d = new Bureaucrat(a);

	c = b;

	std::cout << a;
	std::cout << *b;
	std::cout << *c;
	std::cout << *d;

	delete c;
	delete d;

	return (0);
}