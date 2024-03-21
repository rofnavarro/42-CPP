/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:19:21 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/20 20:28:17 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
:AForm("PresidentialPardonForm", 25, 5, "root")
{
	std::cout << "PresidentialPardonForm default constructor called." << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
:AForm("PresidentialPardonForm", 25, 5, target)
{
	std::cout << "PresidentialPardonForm target constructor called." << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &presidentialpardonform)
:AForm("PresidentialPardonForm", 25, 5, presidentialpardonform._target)
{
	std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
	*this = presidentialpardonform;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm has been expired." << std::endl;
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	std::cout << "PresidentialPardonForm assignment operator called." << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (this->getIsSigned() == false)
			throw PresidentialPardonForm::NotSignedException();
		AForm::execute(executor);
		
		std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cerr << e.what() << std::endl;
	}
	return ;
}
