#pragma once

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
private:
	std::string			_type;
	Brain				*_brain;
public:
						Dog(void);
						Dog(const Dog &Dog);
						~Dog(void);

	Dog					&operator=(const Dog &rhs);

	const std::string	&getType(void) const;
	const std::string	&getIdea(int index) const;
	void				setIdea(const std::string &idea);

	void				makeSound(void) const;
};

#endif