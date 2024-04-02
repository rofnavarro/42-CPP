/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:53:37 by rferrero          #+#    #+#             */
/*   Updated: 2024/04/01 12:04:27 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Must enter a csv file as an argument!" << std::endl;
		return (1);
	}

	BitcoinExchange	*btc;
	try
	{
		btc = new BitcoinExchange("data.csv", argv[1]);
		btc->run();	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete btc;

	return (0);
}