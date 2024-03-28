#pragma once

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void	iter(T *array, size_t size, void (*f)(const T &))
{
	for (size_t counter = 0; counter < size; counter++)
		f(array[counter]);	
	return ;
}

template<typename T>
void	print_value(const T &value)
{
	std::cout << value << std::endl;
	return ;
}

#endif