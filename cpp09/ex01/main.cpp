/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:52:35 by rferrero          #+#    #+#             */
/*   Updated: 2024/04/01 13:02:26 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	RPN		calculator;
	double	result;

	if (argc != 2)
	{
		std::cout << "Must enter a valid expression!" << std::endl;
		return (1);
	}	
	try
	{
		result = calculator.run(argv[1]);
		std::cout << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}