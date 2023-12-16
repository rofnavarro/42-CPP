#pragma once

#ifndef AAnimal_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
protected:
	std::string					_type;
public:
								AAnimal(void);
								AAnimal(const AAnimal &aAnimal);
	virtual						~AAnimal(void);

	AAnimal						&operator=(const AAnimal &rhs);

	virtual const std::string	&getType(void) const;
	
	virtual void				makeSound(void) const;
};

#endif