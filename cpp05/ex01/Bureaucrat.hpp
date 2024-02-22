#pragma	once

#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class	Bureaucrat
{
private:
	std::string	_name;
	int			_grade;
	
public:
	class GradetooHighException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class GradetooLowException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

						Bureaucrat(void);
						Bureaucrat(std::string name, int grade);
						Bureaucrat(const Bureaucrat &bureaucrat);
						~Bureaucrat(void);

	Bureaucrat			&operator=(const Bureaucrat &rhs);

	const std::string	&getName(void) const;
	const int			&getGrade(void) const;

	void				incrementGrade(void);
	void				decrementGrade(void);
	void				signForm(Form &form) const;

};

std::ostream &operator<<(std::ostream &lhs, const Bureaucrat &rhs);

#endif