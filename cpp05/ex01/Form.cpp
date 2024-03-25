/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:54:56 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/24 20:14:46 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(void)
:_name("Default"), _gradeToSign(150), _gradeToExecute(150), _isSigned(false)
{
	std::cout << this->_name << " form constructor called." << std::endl;
	return ;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
:_name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false)
{
	try
	{
		if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
			throw Form::GradetooLowToCreateException();
		else if (gradeToSign < 1 || gradeToExecute < 1)
			throw Form::GradetooHighToCreateException();
		else
			std::cout << this->_name << " form constructor called." << std::endl;
	}
	catch(const std::exception& e)
	{
		// std::cout << e.what() << std::endl;
		std::cerr << e.what() << std::endl;
	}
	return ;
}

Form::Form(const Form &form)
:_name(form._name + " Copy"), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute)
{
	std::cout << "Form copy constructor called." << std::endl;
	*this = form;
	return ;
}

Form::~Form(void)
{
	std::cout << this->_name << " form has expired." << std::endl;
	return ;
}

Form	&Form::operator=(const Form &rhs)
{
	std::cout << "Form assignment operator called." << std::endl;
	if (this != &rhs)
	{
		const_cast	<std::string &>(this->_name) = rhs.getName() + " Assigned";
		const_cast	<int &>(this->_gradeToSign) = rhs.getGradeToSign();
		const_cast	<int &>(this->_gradeToExecute) = rhs.getGradeToExecute();
		this->_isSigned = rhs.getIsSigned();
	}
	return (*this);
}

const std::string	&Form::getName(void) const
{
	return (this->_name);
}

const int	&Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

const int	&Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

const bool	&Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	try
	{
		if (this->getIsSigned())
			throw Form::AlreadySignedException();
		if (bureaucrat.getGrade() > this->_gradeToSign)
			throw Form::GradetooLowToSignException();
		else
		{
			this->_isSigned = true;
			std::cout << bureaucrat.getName() << " signed " << this->_name << "." <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		// std::cout << e.what() << std::endl;
		std::cerr << e.what() << std::endl;
	}
	return ;
}

std::ostream	&operator<<(std::ostream &lhs, const Form &rhs)
{
	if (rhs.getIsSigned() == true)
		lhs << "Form " << rhs.getName() << " IS signed." << std::endl;
	else
		lhs << "Form " << rhs.getName() << " IS NOT signed." << std::endl;
	lhs << "Grade to sign: " << rhs.getGradeToSign() << "." << std::endl;
	lhs << "Grade to execute: " << rhs.getGradeToExecute() << "." << std::endl;
	return (lhs);
}

const char	*Form::GradetooLowToCreateException::what() const throw()
{
	return ("Grade to sign or to execute the form is too low!");
}

const char	*Form::GradetooHighToCreateException::what() const throw()
{
	return ("Grade to sign or to execute the form is too high!");
}

const char	*Form::GradetooLowToSignException::what() const throw()
{
	return ("Grade of the bureaucrat is too low to sign the form!");
}

const char	*Form::AlreadySignedException::what() const throw()
{
	return ("Form is already signed!");
}
