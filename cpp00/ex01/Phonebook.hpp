#pragma once

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

class Phonebook
{
private:
	Contact	_contacts[8];
	int		_i;
public:
			Phonebook();
			~Phonebook();

	void	add_contact();
	void	search_contact();
	void	print_contact();
};

#endif