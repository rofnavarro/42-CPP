#pragma	once

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class	Bureaucrat;

class	AForm
{
private:
	std::string	_name;
	int			_gradeToSign;
	int			_gradeToExecute;
	bool		_isSigned;

public:
	class	GradetooLowToCreateException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class	GradetooHighToCreateException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class	GradetooLowToSignException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class	AlreadySignedException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

						AForm(void);
						AForm(std::string name, int gradeToSign, int gradeToExecute);
						AForm(const AForm &aform);
						~AForm(void);

	AForm				&operator=(const AForm &rhs);

	const std::string	&getName(void) const;
	const int			&getGradeToSign(void) const;
	const int			&getGradeToExecute(void) const;
	const bool			&getIsSigned(void) const;

	void				beSigned(Bureaucrat &bureaucrat);

};

std::ostream	&operator<<(std::ostream &lhs, const AForm &rhs);

#endif