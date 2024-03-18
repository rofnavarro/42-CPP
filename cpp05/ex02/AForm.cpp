/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:54:56 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/18 17:36:47 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(void)
:_name("Default"), _gradeToSign(150), _gradeToExecute(150), _isSigned(false)
{
	std::cout << this->_name << " Aform constructor called." << std::endl;
	return ;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
{
	try
	{
		if (gradeToSign > 150 || gradeToExecute > 150 || \
			gradeToSign < 1 || gradeToExecute < 1)
		{
			this->_name = "Invalid";
			this->_gradeToSign = 0;
			this->_gradeToExecute = 0;
			this->_isSigned = false;
			if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
				throw AForm::GradetooLowToCreateException();
			else
				throw AForm::GradetooHighToCreateException();
		}
		else
		{
			this->_name = name;
			this->_gradeToSign = gradeToSign;
			this->_gradeToExecute = gradeToExecute;
			this->_isSigned = false;
			std::cout << this->_name << " Aform constructor called." << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cerr << e.what() << std::endl;
	}
	return ;
}

AForm::AForm(const AForm &aform)
:_name(aform._name + " Copy"), _gradeToSign(aform._gradeToSign), _gradeToExecute(aform._gradeToExecute)
{
	std::cout << "AForm copy constructor called." << std::endl;
	*this = aform;
	return ;
}

AForm::~AForm(void)
{
	std::cout << this->_name << " Aform has expired." << std::endl;
	return ;
}

AForm	&AForm::operator=(const AForm &rhs)
{
	std::cout << "AForm assignment operator called." << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_gradeToSign = rhs._gradeToSign;
		this->_gradeToExecute = rhs._gradeToExecute;
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

const std::string	&AForm::getName(void) const
{
	return (this->_name);
}

const int	&AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

const int	&AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

const bool	&AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	try
	{
		if (this->getIsSigned())
			throw AForm::AlreadySignedException();
		if (bureaucrat.getGrade() > this->_gradeToSign)
			throw AForm::GradetooLowToSignException();
		else
		{
			this->_isSigned = true;
			std::cout << bureaucrat.getName() << " signed " << this->_name << "." <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cerr << e.what() << std::endl;
	}
	return ;
}

std::ostream	&operator<<(std::ostream &lhs, const AForm &rhs)
{
	if (rhs.getIsSigned() == true)
		lhs << "AForm " << rhs.getName() << " IS signed." << std::endl;
	else
		lhs << "AForm " << rhs.getName() << " IS NOT signed." << std::endl;
	lhs << "Grade to sign: " << rhs.getGradeToSign() << "." << std::endl;
	lhs << "Grade to execute: " << rhs.getGradeToExecute() << "." << std::endl;
	return (lhs);
}

const char	*AForm::GradetooLowToCreateException::what() const throw()
{
	return ("Grade to sign or to execute the Aform is too low!");
}

const char	*AForm::GradetooHighToCreateException::what() const throw()
{
	return ("Grade to sign or to execute the Aform is too high!");
}

const char	*AForm::GradetooLowToSignException::what() const throw()
{
	return ("Grade of the bureaucrat is too low to sign the Aform!");
}

const char	*AForm::AlreadySignedException::what() const throw()
{
	return ("AForm is already signed!");
}
