/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:20:10 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/01 21:22:54 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	std::string	complain[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Harl		Karen;

	srand(time(NULL));

	Karen.complain(complain[rand() % 4]);
	Karen.complain(complain[rand() % 4]);
	Karen.complain(complain[rand() % 4]);
	Karen.complain(complain[rand() % 4]);
	Karen.complain(complain[rand() % 4]);
	Karen.complain(complain[rand() % 4]);
	
	return (0);
}
