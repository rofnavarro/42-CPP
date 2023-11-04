/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:10:41 by rferrero          #+#    #+#             */
/*   Updated: 2023/11/04 14:45:06 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	std::string	str;
	
	if (argc >= 2)
	{
		for (int i = 1; i < argc; i++)
		{
			str = argv[i];
			for (size_t j = 0; j < str.length(); j++)
				str[j] = toupper(str[j]);
			std::cout << str;
			if (i != argc - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
