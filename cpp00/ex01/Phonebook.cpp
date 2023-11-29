/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:53:28 by rferrero          #+#    #+#             */
/*   Updated: 2023/11/29 15:52:27 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	inputNbrValidation(std::string input)
{
	std::string::iterator	i;

	for (i = input.begin(); i != input.end(); i++)
	{
		if (!isdigit(*i))
			return (1);
	}
	return (0);
}

int	inputStrValidation(std::string input)
{
	std::string::iterator	i;

	for (i = input.begin(); i != input.end(); i++)
	{
		if (!isprint(*i))
			return(1);
	}
	return(0);
}

Phonebook::Phonebook()
{
	_i = 0;
}

Phonebook::~Phonebook()
{
	while (!_contacts.empty())
		_contacts.pop();
}

void	Phonebook::addContact()
{
	Contact		newContact;
	std::string	input;

	if (this->_i < 8)
	{
		std::cout << "Adding a contact to your phonebook..." << std::endl;
		std::cout << "Firstname: ";
		std::getline(std::cin, input);
		while (inputStrValidation(input) != 0)
		{
			std::cout << "Please, insert a vallid first name" << std::endl;
			std::cout << "Firstname: ";
			std::getline(std::cin, input);
		}
		newContact.setFirstName(input);
		std::cout << "Lastname: ";
		std::getline(std::cin, input);
		while (inputStrValidation(input) != 0)
		{
			std::cout << "Please, insert a vallid last name" << std::endl;
			std::cout << "Lastname: ";
			std::getline(std::cin, input);
		}
		newContact.setLastName(input);
		std::cout << "Nickname: ";
		std::getline(std::cin, input);
		while (inputStrValidation(input) != 0)
		{
			std::cout << "Please, insert a vallid nick name" << std::endl;
			std::cout << "Nickname: ";
			std::getline(std::cin, input);
		}
		newContact.setNickName(input);
		std::cout << "Phone Number (only numbers): ";
		std::getline(std::cin, input);
		while (inputNbrValidation(input) != 0)
		{
			std::cout << "Please, insert a vallid phone number" << std::endl;
			std::cout << "Phone Number (only numbers): ";
			std::getline(std::cin, input);
		}
		newContact.setPhoneNumber(input);
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, input);
		while (inputStrValidation(input) != 0)
		{
			std::cout << "Please, insert a vallid darkest secret" << std::endl;
			std::cout << "Darkest Secret: ";
			std::getline(std::cin, input);
		}
		newContact.setDarkestSecret(input);
		this->_contacts.push(newContact);
		this->_i++;
	}
	else
	{
		this->_contacts.pop();
		this->_i--;
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
	Phonebook::~Phonebook();
	std::cout << "...finishing" << std::endl;
	std::cout << "Program Finished" << std::endl;
	exit(0);
}
