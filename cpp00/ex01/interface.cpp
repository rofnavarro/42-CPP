/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:41:14 by rferrero          #+#    #+#             */
/*   Updated: 2023/11/26 20:47:19 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

void	start_interface()
{
	std::cout << "# Phonebook" << std::endl;
	std::cout << "# Please enter you command (ADD, SEARCH or EXIT)" << std::endl;
}

void	exit_interface()
{
	std::cout << "...finishing" << std::endl;
	std::cout << "Program Finished" << std::endl;
}
