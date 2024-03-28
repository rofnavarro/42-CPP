/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:06:52 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/27 21:26:53 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Default Serializer constructor called." << std::endl;
	return ;
}

Serializer::Serializer(const Serializer &serializer)
{
	std::cout << "Serializer copy constructor called." << std::endl;
	*this = serializer;
	return ;
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer destructor called." << std::endl;
	return ;
}

Serializer	&Serializer::operator=(const Serializer &rhs)
{
	std::cout << "Serializer assignment operator called." << std::endl;
	(void)rhs;
	return (*this);
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t	serialized = reinterpret_cast<uintptr_t>(ptr);
	return (serialized);
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data	*deserialized = reinterpret_cast<Data *>(raw);
	return (deserialized);
}
