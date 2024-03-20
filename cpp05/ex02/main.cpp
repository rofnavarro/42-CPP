/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:05:00 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/20 16:19:15 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat				*a = new Bureaucrat("Jose", 150);

	std::cout << "*********************** SHRUBBERRY ***********************" << std::endl;

	ShrubberyCreationForm	b41("root");

	a->signForm(b41);
	b41.beSigned(*a);
	b41.execute(*a);

	std::cout << "*********************** ROBOTOMY ***********************" << std::endl;


	// std::cout << "*********************** PRESIDENTIAL ***********************" << std::endl;

	delete a;
	return (0);
}