#pragma once

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
	std::string			_type;
public:
						WrongAnimal(void);
						WrongAnimal(const WrongAnimal &wrongAnimal);
						~WrongAnimal(void);

	WrongAnimal			&operator=(const WrongAnimal &rhs);

	const std::string	&getType(void) const;

	void				makeSound(void) const;
};

#endif