/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:53:39 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/28 18:00:52 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	std::string	arr[2] = {"Hello", "World"};

	::iter(arr, 2, print_value);

	int	arr2[3] = {4, 9, 17};

	::iter(arr2, 3, print_value);

	return (0);
}