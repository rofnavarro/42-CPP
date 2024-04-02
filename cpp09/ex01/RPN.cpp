/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:33:34 by rferrero          #+#    #+#             */
/*   Updated: 2024/04/01 13:23:18 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	return ;
}

RPN::RPN(const RPN &rpn)
{
	*this = rpn;
	return ;
}

RPN::~RPN(void)
{
	return ;
}

RPN	&RPN::operator=(const RPN &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

int	RPN::calculate(int right, int left, char operand)
{
	if (operand == '+')
		return (left + right);
	else if (operand == '-')
		return (left - right);
	else if (operand == '/')
		return (left / right);
	return (left * right);
}


int	RPN::run(std::string input)
{
	std::stack<int>	stack;
	std::string			token(input);
	int					i = -1;

	while (token[++i])
	{
		if (token[i] == ' ')
			continue ;
		else if (isdigit(token[i]))
			stack.push(token[i] - '0');
		else if (token[i] == '+' || token[i] == '-' || token[i] == '/' || token[i] == '*')
		{
			if (stack.size() < 2)
				throw RPN::NotEnoughNumbersException();
			int	right = stack.top();
			stack.pop();
			int	left = stack.top();
			stack.pop();
			int	ret = RPN::calculate(right, left, token[i]);
			stack.push(ret);
		}
		else
			throw RPN::InvalidInputException();
	}
	return (stack.top());
}

const char	*RPN::InvalidInputException::what() const throw()
{
	return ("Invalid Input!");
};

const char	*RPN::NotEnoughNumbersException::what() const throw()
{
	return ("Not enough numbers in stack!");
};
