#pragma once

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
private:
	std::string			_ideas[100];
	int					_counter;
public:
						Brain(void);
						Brain(const Brain &brain);
						~Brain();

	Brain				&operator=(const Brain &rhs);

	const std::string	&getIdea(int index) const;
	void				setIdea(const std::string &idea);
};

#endif