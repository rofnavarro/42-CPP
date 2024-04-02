/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 15:46:34 by rferrero          #+#    #+#             */
/*   Updated: 2024/04/01 15:53:11 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	if (argc < 3)
	{
		std::cout << "Must enter at last TWO  int numbers as argument!" << std::endl;
		return (1);
	}
	PmergeMe	app;

	try
	{
		app.run(argv);	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}