#pragma once

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <queue>
# include <cstdlib>
# include "Contact.hpp"

int	inputStrValidation(std::string input);
int	inputNbrValidation(std::string input);


class Phonebook
{
private:
	std::queue<Contact>	_contacts;
	int					_i;
public:
			Phonebook();
			~Phonebook();

	void	addContact();
	void	searchContact();
	void	printContact();
	void	exitApp();
};


#endif