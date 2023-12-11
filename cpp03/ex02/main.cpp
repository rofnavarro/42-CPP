/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:21:05 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/11 16:52:38 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap	frag("Carl");
	FragTrap	bob("Bob");
	FragTrap	carl;

	ScavTrap	scav("John");

	carl = frag;
	std::cout << carl.getName() << " / " << frag.getName() << std::endl;
	std::cout << carl.getHitPoints() << " / " << frag.getHitPoints() << std::endl;
	std::cout << carl.getEnergyPoints() << " / " << frag.getEnergyPoints() << std::endl;

	bob.attack("Carl");
	std::cout << bob.getName() << " Energy: " << bob.getEnergyPoints() << std::endl;

	carl.takeDamage(8);
	std::cout << carl.getName() << " Hit Points: " << carl.getHitPoints() << std::endl;

	carl.beRepaired(5);
	std::cout << carl.getName() << " Hit Points: " << carl.getHitPoints() << std::endl;

	scav.guardGate();
	frag.highFiveGuys();

	std::cout << "End of combat" << std::endl;

	return (0);
}
