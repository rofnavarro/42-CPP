#pragma once

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void	swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
	return ;
}

template<typename T>
T	min(const T &a, const T &b)
{
	return ((b <= a) ? b : a);
}

template<typename T>
T	max(const T &a, const T &b)
{
	return ((b >= a) ? b : a);
}

#endif