#pragma once

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain				*_brain;
public:
						Dog(void);
						Dog(const Dog &Dog);
						~Dog(void);

	Dog					&operator=(const Dog &rhs);

	const std::string	&getIdea(int index) const;
	void				setIdea(const std::string &idea);

	void				makeSound(void) const;
};

#endif