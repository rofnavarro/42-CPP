/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:21:05 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/11 16:23:16 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	scav("Carl");
	ScavTrap	bob("Bob");
	ScavTrap	carl;

	carl = scav;
	std::cout << carl.getName() << " / " << scav.getName() << std::endl;
	std::cout << carl.getHitPoints() << " / " << scav.getHitPoints() << std::endl;
	std::cout << carl.getEnergyPoints() << " / " << scav.getEnergyPoints() << std::endl;

	bob.attack("Carl");
	std::cout << bob.getName() << " Energy: " << bob.getEnergyPoints() << std::endl;

	carl.takeDamage(8);
	std::cout << carl.getName() << " Hit Points: " << carl.getHitPoints() << std::endl;

	carl.beRepaired(5);
	std::cout << carl.getName() << " Hit Points: " << carl.getHitPoints() << std::endl;

	scav.guardGate();

	std::cout << "End of combat" << std::endl;

	return (0);
}
