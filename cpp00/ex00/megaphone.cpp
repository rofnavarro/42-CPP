/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:10:41 by rferrero          #+#    #+#             */
/*   Updated: 2023/11/30 07:09:22 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	speak_megaphone(std::string str)
{
	for (size_t j = 0; j < str.length(); j++)
		str[j] = toupper(str[j]);
	std::cout << str;
}

int	main(int argc, char **argv)
{
	std::string	str;
	
	if (argc != 1)
	{
		for (int i = 1; argv[i]; i++)
		{
			speak_megaphone(argv[i]);
			if (i != argc - 1)
				std::cout << " ";
		}
	}
	else
		speak_megaphone("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
	std::cout << std::endl;
	return (0);
}
