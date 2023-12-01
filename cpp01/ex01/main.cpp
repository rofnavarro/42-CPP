/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:27:19 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/01 15:32:02 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;

	horde = zombieHorde(10, "feno");
	if (horde == NULL)
	{
		std::cerr << "Fail to allocate the horde!" << std::endl;
		return (1);
	}
	for (int i = 0; i < 10; i++)
		horde[i].announce();
	delete[] horde;
}
