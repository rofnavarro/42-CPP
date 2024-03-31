/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 15:03:18 by rferrero          #+#    #+#             */
/*   Updated: 2024/03/31 16:31:04 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int	main(void)
{
	//	Test 1
	Span	arr(4);

	arr.addNumber(55);
	try
	{
		std::cout << arr[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	arr.addNumber(42);
	try
	{
		std::cout << arr[2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	arr.addNumber(5);
	try
	{
		std::cout << arr[2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	arr.addNumber(6);
	try
	{
		std::cout << arr[3] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "Shortest Span: " << arr.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << arr.longestSpan() << std::endl;

	//	Test 2
	Span	arr2(10000);
	arr2.fillNumber();
	for (int i = 0; i < 10000; i++)
		std::cout << "Value: " << arr2[i] << std::endl;
	
	std::cout << "Shortest Span: " << arr2.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << arr2.longestSpan() << std::endl;	

	//	Test 3
	Span	sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return (0);
}