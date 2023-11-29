/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:05:25 by rferrero          #+#    #+#             */
/*   Updated: 2023/11/29 14:09:53 by rferrero         ###   ########.fr       */
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
	this->_firstName = first;
}

void	Contact::setLastName(std::string last)
{
	this->_lastName = last;
}

void	Contact::setNickName(std::string nick)
{
	this->_nickName = nick;
}

void	Contact::setPhoneNumber(std::string phone)
{
	this->_phoneNumber = phone;
}

void	Contact::setDarkestSecret(std::string secret)
{
	this->_darkestSecret = secret;
}

std::string	Contact::getFirstName(void)
{
	return (this->_firstName);
}

std::string	Contact::getLastName(void)
{
	return (this->_lastName);
}

std::string	Contact::getNickName(void)
{
	return (this->_nickName);
}

std::string	Contact::getPhoneNumber(void)
{
	return (this->_phoneNumber);
}

std::string	Contact::getDarkestSecret(void)
{
	return (this->_darkestSecret);
}
