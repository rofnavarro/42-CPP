#pragma	once

#ifndef	BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>

class Bureaucrat
{
private:
	std::string			_name;
	int					_grade;
public:
						Bureaucrat(void);
						Bureaucrat(const Bureaucrat &bureaucrat);
						~Bureaucrat(void);

	Bureaucrat			&operator=(const Bureaucrat &rhs);

	const std::string	&getName(void) const;
	const int			&getGrade(void) const;

};

std::ostream &operator<<(std::ostream &lhs, Bureaucrat const &bureaucrat)
{
	lhs << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << "." << std::endl;
	return (lhs);
}

#endif