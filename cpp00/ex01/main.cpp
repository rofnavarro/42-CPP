/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 01:30:00 by rferrero          #+#    #+#             */
/*   Updated: 2023/11/29 19:15:51 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int	main(void)
{
	Phonebook	agenda;
	std::string	input;

	std::cout << "# Your Personal Phonebook" << std::endl;
	while (!std::cin.eof())
	{
		std::cout << "# Please enter you command (ADD, SEARCH or EXIT)" << std::endl;
		std::getline(std::cin, input);
		agenda.exitApp(input);
		if (input == "ADD")
			agenda.addContact();
		else if(input == "SEARCH")
			agenda.searchContact();
		else
			std::cout << "# Please enter a valid command" << std::endl;
	}
}
