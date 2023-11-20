/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:05:25 by rferrero          #+#    #+#             */
/*   Updated: 2023/11/04 15:15:49 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void	Contact::setFirstName(std::string first)
{
	this->firstName = first;
}

void	Contact::setLastName(std::string last)
{
	this->lastName = last
}

void	Contact::setNickName(std::string nick)
{
	this->nickName = nick;
}

void	Contact::setPhoneNumber(std::String phone)
{
	this->phoneNumber = phone;
}

void	Contact::setDarkestSecret(std::string secret)
{
	this->darkestSecret = secret;
}

std::string	Contact::getFirstName(void)
{
	return (this->firstName);
}

std::string	Contact::getLastName(void)
{
	return (this->lastName);
}

std::string	Contact::getNickName(void)
{
	return (this->nickName);
}

std::string	Contact::getPhoneNumber(void)
{
	return (this->phoneNumber);
}

std::string	Contact::getDarkestSecret(void)
{
	return (this->darkestSecret);
}
