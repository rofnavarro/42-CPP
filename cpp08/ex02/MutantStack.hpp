#pragma once

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template<typename T>
class	MutantStack: public std::stack<T>
{
private:

public:
				MutantStack(void): std::stack<T>() {return ;};
				MutantStack(const MutantStack &mutantstack): std::stack<T>(mutantstack) {return ;};

				~MutantStack(void) {return ;};

	MutantStack	&operator=(const MutantStack &rhs)
	{
		std::stack<T>::operator=(rhs);
		return (*this);
	};

	typedef typename	std::stack<T>::container_type::iterator 		iterator;
	typedef typename	std::stack<T>::container_type::const_iterator	const_iterator;
	typedef typename	std::stack<T>::container_type::reverse_iterator	reverse_iterator;

	iterator			begin()
	{
		return (std::stack<T>::c.begin());
	}
	const_iterator		begin() const
	{
		return (std::stack<T>::c.begin());
	}
	reverse_iterator	rbegin()
	{
		return (std::stack<T>::c.rbegin());
	}

	iterator			end()
	{
		return (std::stack<T>::c.end());
	}
	const_iterator		end() const
	{
		return (std::stack<T>::c.end());
	}
	reverse_iterator	rend()
	{
		return (std::stack<T>::c.rend());
	}

};

#endif