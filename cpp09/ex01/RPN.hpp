#pragma once

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <cstdlib>
# include <stack>


class	RPN
{
private:
	std::stack<int>	_data;
public:
	class	InvalidInputException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
	class	NotEnoughNumbersException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
			RPN(void);
			RPN(const RPN &rpn);

			~RPN(void);

	RPN		&operator=(const RPN &rhs);

	int		calculate(int right, int left, char operand);
	int		run(std::string input);

};

#endif