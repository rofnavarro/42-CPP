/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:43:21 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/20 21:27:43 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called." << std::endl;
	return ;
}

Intern::Intern(const Intern &intern)
{
	std::cout << "Intern copy constructor called." << std::endl;
	*this = intern;
	return ;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called." << std::endl;
	return ;
}

Intern	&Intern::operator=(const Intern &rhs)
{
	std::cout << "Intern assignment operator called." << std::endl;
	(void)rhs;
	return (*this);
}

static	AForm	*makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

static	AForm	*makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

static	AForm	*makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	try
	{
		
		AForm	*(*functions[3])(std::string) = {makePresidentialPardonForm, makeRobotomyRequestForm, makeShrubberyCreationForm};
		std::string	name[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
		int	index = 99;
		for (int i = 0; i < 3; i++)
		{
			if (form == name[i])
			{
				std::cout << "Intern creates " << form << "." << std::endl;
				index = i;
			}
		}
		if (index != 99)
			return (functions[index](target));
		else
			throw Intern::InvalidFormException();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cerr << e.what() << std::endl;
	}
	return (NULL);
}

const char	*Intern::InvalidFormException::what() const throw()
{
	return ("Invalid type of form!");
}
