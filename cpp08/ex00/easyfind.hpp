#pragma once

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template<typename T>
typename	T::iterator	easyfind(T &container, int value)
{
	typename	T::iterator	counter;
	counter = std::find(container.begin(), container.end(), value);

	try
	{
		if (counter == container.end())
			throw std::logic_error("Value not found: ");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << value << std::endl;
	}
	return (counter);
}

#endif