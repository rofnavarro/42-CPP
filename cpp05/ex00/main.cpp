/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:35:06 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/24 20:11:27 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	a;
	Bureaucrat	*b;
	Bureaucrat	*c = new Bureaucrat("carlos", 5);
	Bureaucrat	*d = new Bureaucrat(a);
	Bureaucrat	*e = new Bureaucrat("andre", -20);
	Bureaucrat	f;

	std::cout << "**********************" <<std::endl;

	b = c;
	f = a;

	std::cout << "**********************" <<std::endl;

	std::cout << a;
	std::cout << *b;
	std::cout << *c;
	std::cout << *d;
	std::cout << *e;
	std::cout << f;

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
	f.decrementGrade();
	std::cout << f;


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
	f.incrementGrade();
	std::cout << f;



	std::cout << "**********************" <<std::endl;

	delete b;
	delete d;
	delete e;

	return (0);
}