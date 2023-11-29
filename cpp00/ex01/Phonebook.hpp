#pragma once

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <locale>

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
	void	printContact();
	void	exitApp();
};

#endif