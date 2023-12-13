/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:21:05 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/13 12:59:13 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap	dia("Carl");
	DiamondTrap	bob("Bob");
	// DiamondTrap	yo;

	// ScavTrap	scav("John");
	// FragTrap	frag("Eddie");

	// yo = bob;

	dia.getName();

	dia.attack("Bob");

	// scav.guardGate();
	// frag.highFiveGuys();

	dia.whoAmI();

	std::cout << "End of combat" << std::endl;

	return (0);
}
