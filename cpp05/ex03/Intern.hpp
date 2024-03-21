#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class	Intern
{
public:
	class	InvalidFormException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

			Intern(void);
			Intern(const Intern &intern);
			~Intern(void);

	Intern	&operator=(const Intern &rhs);

	AForm	*makeForm(std::string form, std::string target);

};

#endif