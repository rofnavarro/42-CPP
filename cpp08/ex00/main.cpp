/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 14:05:58 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/31 14:25:31 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <vector>
#include <deque>

int	main(void)
{
	std::vector<int>	vec;
	int					base = 9;

	for (int i = 0; i <= 9; i++)
	{
		vec.push_back(base);
		base++;
	}
	
	std::cout << "Vector:" << std::endl;
	for (std::vector<int>::iterator	i = vec.begin(); i != vec.end(); i++)
		std::cout << "value: " << *i << std::endl;

	std::vector<int>::iterator	vec_it = easyfind(vec, 15);
	std::cout << "Value Found: " << *vec_it << std::endl;

	std::vector<int>::iterator	vec_error = easyfind(vec, 4);
	
	vec_error = easyfind(vec, 11);
	std::cout << "Value Found: " << *vec_error << std::endl;

	return (0);
}