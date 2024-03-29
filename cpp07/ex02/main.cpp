/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 21:36:49 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/28 22:13:12 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int	main(void)
{
	Array<int>	ref(4);

	ref[0] = 5;
	ref[1] = 19;
	ref[2] = 31;
	ref[3] = 89;

	for (unsigned int x = 0; x <= ref.size(); x++)
	try
	{
		std::cout << ref[x] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}