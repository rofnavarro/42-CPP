/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:36:30 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/27 11:53:04 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Need ONE argument to run the converter." << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}