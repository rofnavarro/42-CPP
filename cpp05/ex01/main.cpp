/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 14:05:00 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/18 17:25:23 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	*a = new Bureaucrat("Jose", 20);

	Form		*b41 = new Form("Marriage", 130, 100);
	Form		c41;

	std::cout << "**********************" << std::endl;

	c41 = *b41;

	std::cout << "**********************" << std::endl;

	std::cout << *a;
	std::cout << "B41:\n" << *b41;
	std::cout << "C41:\n" << c41;

	std::cout << "**********************" << std::endl;

	a->signForm(c41);

	std::cout << "**********************" << std::endl;

	std::cout << "B41:\n" << *b41;
	std::cout << "C41:\n" << c41;

	std::cout << "**********************" << std::endl;

	delete a;
	delete b41;
	return (0);
}