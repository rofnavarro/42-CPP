/* *************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:05:00 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/20 19:17:45 by rferrero         ###   ########.fr       */
/*                                                                            */
/* *************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	std::cout << "********************************************** BUREAUCRATS **********************************************" << std::endl;

	Bureaucrat				*a = new Bureaucrat("Jose", 150);
	Bureaucrat				*b = new Bureaucrat("Carlos", 2);
	
	std::cout << "********************************************** SHRUBBERRY **********************************************" << std::endl;

	ShrubberyCreationForm	b41("root");
	ShrubberyCreationForm	b42("home");

	a->signForm(b41);
	b41.execute(*a);

	b42.beSigned(*b);
	b42.execute(*b);

	std::cout << "********************************************** ROBOTOMY **********************************************" << std::endl;

	RobotomyRequestForm		c41("root");
	RobotomyRequestForm		c42("home");

	a->signForm(c41);
	c41.execute(*a);

	c42.beSigned(*b);
	c42.execute(*b);

	std::cout << "********************************************** PRESIDENTIAL **********************************************" << std::endl;


	std::cout << "********************************************** CLEAN UP **********************************************" << std::endl;

	delete a;
	delete b;
	return (0);
}