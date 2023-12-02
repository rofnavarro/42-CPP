/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:09:44 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/01 21:42:54 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	this->_index[0] = "DEBUG";
	this->_index[1] = "INFO";
	this->_index[2] = "WARNING";
	this->_index[3] = "ERROR";
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
	return ;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" <<std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	return ;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}

void	Harl::complain(std::string level)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (this->_index[i] == level)
			break ;
		i++;
	}
	while (i < 5)
	{
		switch (i)
		{
			case (0):
				this->debug();
				break ;
			case (1):
				this->info();
				break ;
			case (2):
				this->warning();
				break ;
			case (3):
				this->error();
				i = 5;
				break ;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
				break ;
		}
		i++;
	}
	return ;
}
