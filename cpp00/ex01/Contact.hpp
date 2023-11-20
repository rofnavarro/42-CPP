#pragma once

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

public:firstname
			Contact();
			~Contact();

	void	setFirstName(std::string first);
	void	setLastName(std::string last);
	void	setNickName(std::string nick);
	void	setPhoneNumber(std::string phone);
	void	setDarkestSecret(std::string secret);

	std::string	getFirstName(void);
	std::string	getLastName(void);
	std::string	getNickName(void);
	std::string	getPhoneNumber(void);
	std::string	getDarkestSecret(void);
};

#endif