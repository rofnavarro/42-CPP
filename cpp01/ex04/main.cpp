/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:47:32 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/01 21:01:54 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

int	argCheck(int argc)
{
	if (argc != 4)
	{
		std::cout << "Please insert <filename> <search_term> <replace_term>." << std::endl;
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argCheck(argc) == 1)
		return (1);

	Converter	converter(argv[1], argv[2], argv[3]);

	converter.work();
	return (0);
}
