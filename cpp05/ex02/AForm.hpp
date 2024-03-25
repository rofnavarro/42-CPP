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
	const std::string	_name;
	const int			_gradeToSign;
	const int			_gradeToExecute;
	bool				_isSigned;

protected:
	std::string			_target;

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

	class	NotSignedException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class	FileNotCreatedException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

						AForm(void);
						AForm(std::string name, int gradeToSign, int gradeToExecute, std::string target);
						AForm(const AForm &aform);
						~AForm(void);

	AForm				&operator=(const AForm &rhs);

	const std::string	&getName(void) const;
	const int			&getGradeToSign(void) const;
	const int			&getGradeToExecute(void) const;
	const bool			&getIsSigned(void) const;

	void				beSigned(Bureaucrat &bureaucrat);
	virtual	void		execute(Bureaucrat const &executor) const = 0;

};

std::ostream	&operator<<(std::ostream &lhs, const AForm &rhs);

#endif