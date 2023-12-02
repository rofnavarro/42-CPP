/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:20:10 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/01 21:36:51 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl		Karen;

	if (argc != 2)
	{
		std::cout << "Please insert a <level> (\"DEBUG\", \"INFO\", \"WARNING\" or \"ERROR\") or <any_string>" << std::endl;
		return (1);
	}
	Karen.complain(argv[1]);
	return (0);
}
