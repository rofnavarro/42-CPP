/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:21:05 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/11 15:37:43 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	bob("Bob");
	ClapTrap	carll("Carl");
	ClapTrap	carl;

	carl = carll;
	std::cout << carll.getName() << " / " << carl.getName() << std::endl;
	std::cout << carll.getHitPoints() << " / " << carl.getHitPoints() << std::endl;
	std::cout << carll.getEnergyPoints() << " / " << carl.getEnergyPoints() << std::endl;

	bob.attack("Carl");
	std::cout << bob.getName() << " Energy: " << bob.getEnergyPoints() << std::endl;

	carl.takeDamage(8);
	std::cout << carl.getName() << " Hit Points: " << carl.getHitPoints() << std::endl;

	carl.beRepaired(5);
	std::cout << carl.getName() << " Hit Points: " << carl.getHitPoints() << std::endl;

	return (0);
}
