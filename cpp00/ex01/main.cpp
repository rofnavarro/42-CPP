/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 01:30:00 by rferrero          #+#    #+#             */
/*   Updated: 2023/11/27 19:52:56 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Phonebook.hpp>

int	inputStrValidation(std::string input)
{
	int	i;

	while (input[i])
	{
		if (isprint(input[i]) == 0)
			return(1);
	}
	return(0);
}

int	main(int argc, char **argv)
{
	if (argc != 1)
	{
		std::cout <<  << std::endl;
		return (1);
	}
}
