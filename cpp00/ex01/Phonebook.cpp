/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:53:28 by rferrero          #+#    #+#             */
/*   Updated: 2023/11/27 19:52:58 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	_i = 0;
}

Phonebook::~Phonebook()
{

}

void	Phonebook::addContact()
{
	std::string	input;

	std::cout << "Adding a contact to your phonebook..." << std::endl;
	std::cout << "Firstname: ";
	std::getline(std::cin, input);
	while (inputStrValidation(input) != 0)
	{
		std::cout << "Please, insert a vallid first name" << std::endl;
		std::cout << "Firstname: ";
		std::getline(std::cin, input);
	}
}

void	Phonebook::searchContact()
{

}

void	Phonebook::printContact()
{

}

void	Phonebook::exitApp()
{
	std::cout << "...finishing" << std::endl;
	std::cout << "Program Finished" << std::endl;
	exit(0);
}
