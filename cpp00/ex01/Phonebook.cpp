/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2028/11/04 14:58:28 by rferrero          #+#    #+#             */
/*   Updated: 2023/11/29 19:08:11 by rferrero         ###   ########.fr       */
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

void	printHeader()
{
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|          |          |          |          |" << std::endl;
	std::cout << "|" << std::setw(10) << "INDEX";
	std::cout << "|" << std::setw(10) << "FIRST NAME";
	std::cout << "|" << std::setw(10) << "LAST NAME";
	std::cout << "|" << std::setw(10) << "NICKNAME" << "|" << std::endl;;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
}

std::string	convertStr(std::string input)
{
	if (input.length() > 10)
		return (std::string(input.begin(), (input.begin() + 9)) + '.');
	return (input);
}

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
		this->_contacts[_i].setFirstName(input);
		std::cout << "Lastname: ";
		std::getline(std::cin, input);
		while (inputStrValidation(input) != 0)
		{
			std::cout << "Please, insert a vallid last name" << std::endl;
			std::cout << "Lastname: ";
			std::getline(std::cin, input);
		}
		this->_contacts[_i].setLastName(input);
		std::cout << "Nickname: ";
		std::getline(std::cin, input);
		while (inputStrValidation(input) != 0)
		{
			std::cout << "Please, insert a vallid nick name" << std::endl;
			std::cout << "Nickname: ";
			std::getline(std::cin, input);
		}
		this->_contacts[_i].setNickName(input);
		std::cout << "Phone Number (only numbers): ";
		std::getline(std::cin, input);
		while (inputNbrValidation(input) != 0)
		{
			std::cout << "Please, insert a vallid phone number" << std::endl;
			std::cout << "Phone Number (only numbers): ";
			std::getline(std::cin, input);
		}
		this->_contacts[_i].setPhoneNumber(input);
		std::cout << "Darkest Secret: ";
		std::getline(std::cin, input);
		while (inputStrValidation(input) != 0)
		{
			std::cout << "Please, insert a vallid darkest secret" << std::endl;
			std::cout << "Darkest Secret: ";
			std::getline(std::cin, input);
		}
		this->_contacts[_i].setDarkestSecret(input);
		this->_i++;
	}
	else
	{
		for (int i = 0; i + 1 < 8; i++)
			_contacts[i] = _contacts[i + 1];
		this->_i--;
		Phonebook::addContact();
	}
}

void	Phonebook::searchContact()
{
	std::string	tmp;

	printHeader();
	for (int i = 0; i < this->_i; i++)
	{
		std::cout << "|" << std::setw(10) << (i + 1);
		std::cout << "|" << std::setw(10) << convertStr(this->_contacts[i].getFirstName());
		std::cout << "|" << std::setw(10) << convertStr(this->_contacts[i].getLastName());
		std::cout << "|" << std::setw(10) << convertStr(this->_contacts[i].getNickName());
		std::cout << "|" << std::endl;
	}
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	std::cout << std::endl;
	std::cout << "Please chose one contact by the index: ";
	std::getline(std::cin, tmp);
	while (tmp.length() < 1 || tmp.length() > 1)
	{
		if (tmp.length() > 1)
			std::cout << "Please enter one digit number" << std::endl;
		std::cout << "Please chose one contact by the index: ";
		std::getline(std::cin, tmp);
	}
	while (tmp.length() == 1)
	{
		if (tmp[0] < 49 && tmp[0] > this->_i)
		{
			std::cout << "Please, insert a vallid index" << std::endl;
			std::cout << "From 1 to " << (this->_i) << ": ";
			std::getline(std::cin, tmp);
		}
		Phonebook::printContact(tmp[0] - '0');
		break;
	}
}

void	Phonebook::printContact(int	i)
{
	std::cout << "|Index: " << (i) << std::endl;;
	std::cout << "|First Name: " << this->_contacts[i - 1].getFirstName() << std::endl;;
	std::cout << "|Last Name: " << this->_contacts[i - 1].getLastName() << std::endl;;
	std::cout << "|Nickname: " << this->_contacts[i - 1].getNickName() << std::endl;;
	std::cout << "|Phone Number: " << this->_contacts[i - 1].getPhoneNumber() << std::endl;;
	std::cout << "|Darkest Secret: " << this->_contacts[i - 1].getDarkestSecret() << std::endl;;
}

void	Phonebook::exitApp()
{
	Phonebook::~Phonebook();
	std::cout << "...finishing" << std::endl;
	std::cout << "Program Finished" << std::endl;
	exit(0);
}
