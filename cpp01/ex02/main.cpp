/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:45:02 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/01 15:54:45 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*str_ptr = &str;
	std::string	&str_ref = str;
	
	std::cout << &str << std::endl;
	std::cout << &str_ptr << std::endl;
	std::cout << &str_ref << std::endl;

	std::cout << str << std::endl;
	std::cout << *str_ptr << std::endl;
	std::cout << str_ref << std::endl;

	return (0);
}
