#pragma once

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain				*_brain;
public:
						Cat(void);
						Cat(const Cat &cat);
						~Cat(void);

	Cat					&operator=(const Cat &rhs);

	const std::string	&getIdea(int index) const;
	void				setIdea(const std::string &idea);

	void				makeSound(void) const;
};

#endif