/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:42:11 by rferrero          #+#    #+#             */
/*   Updated: 2023/11/29 14:49:26 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int	inputNbrValidation(std::string &input)
{
	std::string::iterator	i;

	for (i = input.begin(); i != input.end(); i++)
	{
		if (!isdigit(*i))
			return (1);
	}
	return (0);
}

int	inputStrValidation(std::string &input)
{
	std::string::iterator	i;

	for (i = input.begin(); i != input.end(); i++)
	{
		if (!isprint(*i))
			return(1);
	}
	return(0);
}
