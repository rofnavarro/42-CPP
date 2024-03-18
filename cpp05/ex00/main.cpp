/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:35:06 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/18 12:16:46 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	a;
	Bureaucrat	*b;
	Bureaucrat	*c = new Bureaucrat("carlos", 5);
	Bureaucrat	*d = new Bureaucrat(a);

	b = c;

	Bureaucrat	*e = new Bureaucrat("andre", -20);

	std::cout << "**********************" <<std::endl;


	std::cout << a;
	std::cout << *b;
	std::cout << *c;
	std::cout << *d;
	std::cout << *e;

	std::cout << "**********************" <<std::endl;

	a.decrementGrade();
	std::cout << a;
	b->decrementGrade();
	std::cout << *b;
	c->decrementGrade();
	std::cout << *c;
	d->decrementGrade();
	std::cout << *d;
	e->decrementGrade();
	std::cout << *e;

	std::cout << "**********************" <<std::endl;


	a.incrementGrade();
	std::cout << a;
	b->incrementGrade();
	std::cout << *b;
	c->incrementGrade();
	std::cout << *c;
	d->incrementGrade();
	std::cout << *d;
	e->incrementGrade();
	std::cout << *e;


	std::cout << "**********************" <<std::endl;

	delete b;
	delete d;
	delete e;

	return (0);
}