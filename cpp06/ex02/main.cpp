/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 22:10:22 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/28 00:05:12 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"

int	main(void)
{
	Base	*p = generate();

	identify(*p);
	identify(p);

	delete p;

	return (0);
}