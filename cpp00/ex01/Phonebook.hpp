#pragma once

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <queue>
# include <cstdlib>
# include <iomanip>

# include "Contact.hpp"

int			inputStrValidation(std::string input);
int			inputNbrValidation(std::string input);
void		printHeader();
std::string	convertStr(std::string input);

class Phonebook
{
private:
	Contact	_contacts[8];
	int		_i;
public:
			Phonebook();
			~Phonebook();

	void	addContact();
	void	searchContact();
	void	printContact(int i);
	void	exitApp();
};


#endif