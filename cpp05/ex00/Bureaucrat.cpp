/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:34:42 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/18 12:10:59 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
:_name("Default"), _grade(150)
{
	std::cout << this->_name << " bureaucrat constructor called." << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	try
	{
		if (grade < 151 && grade > 0)
		{
			this->_name = name;
			this->_grade = grade;
			std::cout << this->_name << " bureaucrat constructor called." << std::endl;
		}
		else
		{
			this->_name = "Broken Bureaucrat";
			this->_grade = 151;
			if (grade > 150)
				throw Bureaucrat::GradetooLowException();
			else
				throw Bureaucrat::GradetooHighException();
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
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
	std::cout << this->_name << " has been destroyed." << std::endl;
	return ;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << "Bureaucrat assignment operator called." << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
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
		if (this->_name == "Broken Bureaucrat")
			throw Bureaucrat::InvalidBurreaucrat();
		if (this->_grade > 1)
			this->_grade--;
		else
			throw Bureaucrat::GradetooHighException();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cerr << e.what() << std::endl;
	}
	return ;
}

void	Bureaucrat::decrementGrade(void)
{
	try
	{
		if (this->_name == "Broken Bureaucrat")
			throw Bureaucrat::InvalidBurreaucrat();
		else if (this->_grade < 150)
			this->_grade++;
		else
			throw Bureaucrat::GradetooLowException();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cerr << e.what() << std::endl;
	}
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

const char	*Bureaucrat::InvalidBurreaucrat::what() const throw()
{
	return ("Broken Burreaucrat... Can't change grade...");
}
