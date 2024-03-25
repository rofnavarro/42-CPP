/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:19:21 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/24 20:46:44 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
:AForm("RobotomyRequestForm", 72, 45, "root")
{
	std::cout << "RobotomyRequestForm default constructor called." << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
:AForm("RobotomyRequestForm", 72, 45, target)
{
	std::cout << "RobotomyRequestForm target constructor called." << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyrequestform)
:AForm("RobotomyRequestForm", 72, 45, robotomyrequestform._target)
{
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
	*this = robotomyrequestform;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm has been expired." << std::endl;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	std::cout << "RobotomyRequestForm assignment operator called." << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (this->getIsSigned() == false)
			throw RobotomyRequestForm::NotSignedException();
		AForm::execute(executor);
		int	chance;

		std::cout << "*blip* *blip* *blip*" << std::endl;
		std::srand(std::time(0));
		chance = std::rand();
		if (chance % 2)
			std::cout << this->_target << " has been robotomized." << std::endl;
		else
			std::cout << "Failed to robotomize " << this->_target << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		// std::cout << e.what() << std::endl;
		std::cerr << e.what() << std::endl;
	}
	return ;
}
