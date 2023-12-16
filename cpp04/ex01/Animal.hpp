#pragma once

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
	std::string			_type;
public:
						Animal(void);
						Animal(const Animal &animal);
	virtual				~Animal(void);

	Animal				&operator=(const Animal &rhs);

	const std::string	&getType(void) const;
	
	virtual void		makeSound(void) const;
};

#endif