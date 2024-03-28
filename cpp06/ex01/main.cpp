/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:15:37 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/27 21:39:06 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"


std::ostream	&operator<<(std::ostream &lhs, const Data &rhs)
{
	lhs << "Name: " << rhs.name << std::endl;
	lhs << "Last Name: " << rhs.lastname << std::endl;
	lhs << "Age: " << rhs.age << std::endl;
	return (lhs);
}

int	main(void)
{
	Data		info = {"Rodrigo", "Ferrero", 37};
	Data		*d_ptr;
	uintptr_t	u_ptr;

	std::cout << info << std:: endl;

	d_ptr = &info;
	u_ptr = Serializer::serialize(d_ptr);

	std::cout << u_ptr << std::endl;
	std::cout << std::endl;

	d_ptr = Serializer::deserialize(u_ptr);
	std::cout << *d_ptr << std::endl;
	return (0);
}