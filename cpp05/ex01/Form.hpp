#pragma	once

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	_name;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	bool				_isSigned;

public:
	class GradetooHighException: public std::exception
	{
		public:
			const char	*what() const throw();
	};

	class GradetooLowException: public std::exception
	{
		public:
			const char	*what() const throw();
	};

						Form(void);
						Form(std::string name, int gradeToSign, int gradeToExecute);
						Form(const Form &form);
						~Form(void);

	Form				&operator=(const Form &rhs);

	const std::string	&getName(void) const;
	const int			&getGradeToSign(void) const;
	const int			&getGradeToExecute(void) const;
	const bool			&getIsSigned(void) const;

	void				beSigned(Bureaucrat &bureaucrat);

};

std::ostream &operator<<(std::ostream &lhs, const Form &rhs);

#endif