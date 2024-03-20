/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:19:21 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/20 20:08:41 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
:AForm("ShrubberyCreationForm", 145, 137, "root")
{
	std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
:AForm("ShrubberyCreationForm", 145, 137, target)
{
	std::cout << "ShrubberyCreationForm target constructor called." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &shrubberycreationform)
:AForm("ShrubberyCreationForm", 145, 137, shrubberycreationform._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
	*this = shrubberycreationform;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm has been expired." << std::endl;
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	std::cout << "ShrubberyCreationForm assignment operator called." << std::endl;
	if (this != &rhs)
		this->_target = rhs._target;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		if (this->getIsSigned() == false)
			throw ShrubberyCreationForm::NotSignedException();
		AForm::execute(executor);
		std::ofstream	file((this->_target + "_shrubbery").c_str());
		
		if (file.fail())
			throw ShrubberyCreationForm::FileNotCreatedException();
		else
		{
			file << "ASCII trees inside it." << std::endl;
			file << "ASCII trees inside it." << std::endl;
			file << "ASCII trees inside it." << std::endl;
			file << "ASCII trees inside it." << std::endl;
			file << "ASCII trees inside it." << std::endl;
			file << "ASCII trees inside it." << std::endl;
			file.close();
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cerr << e.what() << std::endl;
	}
	return ;
}
