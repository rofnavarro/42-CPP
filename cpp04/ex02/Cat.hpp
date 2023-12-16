#pragma once

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
private:
	std::string			_type;
	Brain				*_brain;
public:
						Cat(void);
						Cat(const Cat &cat);
						~Cat(void);

	Cat					&operator=(const Cat &rhs);

	const std::string	&getType(void) const;
	const std::string	&getIdea(int index) const;
	void				setIdea(const std::string &idea);

	void				makeSound(void) const;
};

#endif