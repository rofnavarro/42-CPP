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
#include "Intern.hpp"

int	main(void)
{
	std::cout << "********************************************** INTERN **********************************************" << std::endl;

	Intern	a;
	AForm	*ref;
	AForm	*ref2;
	AForm	*ref3;
	AForm	*ref4;

	
	std::cout << "********************************************** SHRUBBERRY **********************************************" << std::endl;

	ref = a.makeForm("shrubbery creation", "root");
	std::cout << *ref;

	std::cout << "********************************************** ROBOTOMY **********************************************" << std::endl;

	ref2 = a.makeForm("robotomy request", "home");
	std::cout << *ref2;

	std::cout << "********************************************** PRESIDENTIAL **********************************************" << std::endl;

	ref3 = a.makeForm("presidential pardon", "dev");
	std::cout << *ref3;

	std::cout << "********************************************** INVALID **********************************************" << std::endl;

	ref4 = a.makeForm("marriage", "null");

	std::cout << "********************************************** CLEAN UP **********************************************" << std::endl;

	delete ref;
	delete ref2;
	delete ref3;
	delete ref4;

	return (0);
}