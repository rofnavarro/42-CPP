/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:54:56 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/18 11:52:55 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << this->_name << " form constructor called." << std::endl;
	return ;
}

Form::Form(const Form &form)
:_name(form._name + " Copy"), _gradeToSign(form._gradeToSign), _gradeToExecute(form._gradeToExecute)
{
	std::cout << "Form copy constructor called." << std::endl;
	*this = bureaucrat;
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
		this->_name = rhs._name;
		this->_gradeToSign = rhs._gradeToSign;
		this->_gradeToExecute = rhs._gradeToExecute;
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

const std::string	&Form::getName(void) const
{
	return (this->_name);
}

const std::string	&Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

const std::string	&Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

const std::string	&Form::getIsSigned(void) const
{
	return (this->_isSigned);
}