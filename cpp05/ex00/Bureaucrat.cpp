#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
:_name("Default"), _grade(150)
{
	std::cout << self.getName() << " bureaucrat has been created" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	try
	{
		if (grade < 151 || grade > 1)
		{
			self._name = name;
			self._grade = grade;
		}
		else
		{
			if (grade > 150)
				throw Bureaucrat.GradetooLowException();
			else
				throw Bureaucrat.GradetooHighException();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = bureaucrat;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << this->getName() << " has been destroyed" << std::endl;
	return ;
}

std::ostream &operator<<(std::ostream &lhs, Bureaucrat const &bureaucrat)
{
	lhs << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return (lhs);
}
