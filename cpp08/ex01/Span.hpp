#pragma once

#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <stdexcept>
# include <vector>

class	Span
{
private:
	unsigned int		_size;
	std::vector<int>	_vector;

public:
	class	VectorFullException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class	VectorWithOnlyOneValueException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class	InvalidIndexException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

			Span(void);
			Span(unsigned int N);
			Span(const Span &span);

			~Span(void);

	Span	&operator=(const Span &rhs);
	int		&operator[](int index);

	void	addNumber(int value);
	int		shortestSpan(void);
	int		longestSpan(void);

};

#endif