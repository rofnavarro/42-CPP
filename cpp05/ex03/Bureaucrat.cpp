/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:34:42 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/24 20:34:55 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
:_name("Default"), _grade(150)
{
	std::cout << this->getName() << " bureaucrat constructor called." << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
:_name(name), _grade(grade)
{
	try
	{
		if (grade > 150)
			throw Bureaucrat::GradetooLowException();
		else if (grade < 0)
			throw Bureaucrat::GradetooHighException();
		else
			std::cout << this->getName() << " bureaucrat constructor called." << std::endl;
	}
	catch(const std::exception& e)
	{
		// std::cout << e.what() << std::endl;
		std::cerr << e.what() << std::endl;
	}
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
:_name(bureaucrat._name + " Copy")
{
	std::cout << "Bureaucrat copy constructor called." << std::endl;
	*this = bureaucrat;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << this->getName() << " has been destroyed." << std::endl;
	return ;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << "Bureaucrat assignment operator called." << std::endl;
	if (this != &rhs)
	{
		const_cast	<std::string &>(this->_name) = rhs.getName() + " Assigned";
		this->_grade = rhs._grade;
	}
	return (*this);
}

const std::string	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

const int	&Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	try
	{
		if (this->getGrade() > 150 || this->getGrade() < 0)
			throw Bureaucrat::InvalidBurreaucratException();
		else if (this->getGrade() > 1)
			this->_grade--;
		else
			throw Bureaucrat::GradetooHighException();
	}
	catch(const std::exception& e)
	{
		// std::cout << e.what() << std::endl;
		std::cerr << e.what() << std::endl;
	}
	return ;
}

void	Bureaucrat::decrementGrade(void)
{
	try
	{
		if (this->getGrade() > 150 || this->getGrade() < 0)
			throw Bureaucrat::InvalidBurreaucratException();
		else if (this->getGrade() < 150)
			this->_grade++;
		else
			throw Bureaucrat::GradetooLowException();
	}
	catch(const std::exception& e)
	{
		// std::cout << e.what() << std::endl;
		std::cerr << e.what() << std::endl;
	}
	return ;
}

void	Bureaucrat::signForm(AForm &aform)
{
	if (aform.getIsSigned() == true)
		std::cout << this->getName() << " culdn't sign " << aform.getName() << " because the form is already signed." << std::endl;
	try
	{
		aform.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		// std::cout << this->getName() << " couldn't sign " << aform.getName() << " because: " << e.what() << std::endl;
		std::cerr << this->getName() << " couldn't sign " << aform.getName() << " because: " << e.what() << std::endl;
	}
	return ;
}

void	Bureaucrat::executeForm(AForm const &aform)
{
	aform.execute(*this);
	return ;
}

std::ostream	&operator<<(std::ostream &lhs, const Bureaucrat &rhs)
{
	lhs << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return (lhs);
}

const char	*Bureaucrat::GradetooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char	*Bureaucrat::GradetooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char	*Bureaucrat::InvalidBurreaucratException::what() const throw()
{
	return ("Broken Burreaucrat... Can't change grade...");
}
