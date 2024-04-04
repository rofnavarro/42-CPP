/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:36:25 by rferrero          #+#    #+#             */
/*   Updated: 2024/04/02 12:05:22 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	return ;
}

PmergeMe::PmergeMe(const PmergeMe &pmergeme)
{
	*this = pmergeme;
	return ;
}

PmergeMe::~PmergeMe(void)
{
	return ;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
		*this = rhs;
	return (*this);
}

void	PmergeMe::run(char **input)
{
	this->getInput(input);
	this->printBefore();
	this->sortVector();
	this->sortDeque();
	this->printAfter();
	this->printDuration();
	return ;
}

void	PmergeMe::getInput(char **input)
{
	std::istringstream	str;
	int					value;

	for (int i = 1; input[i] != NULL; i++)
	{
		if (std::string(input[i]).find_first_not_of("0123456789") != std::string::npos)
			throw PmergeMe::InvalidInputException();
		else
		{
			str.str(input[i]);
			str >> value;
			this->_unsorted.push_back(value);
			str.clear();
		}
	}
	return ;
}

void	PmergeMe::printBefore(void)
{
	std::cout << "Before: ";
	for (size_t i = 0; i < this->_unsorted.size(); i ++)
		std::cout << this->_unsorted[i] << " ";
	std::cout << std::endl;
	return ;
}

void	PmergeMe::printAfter(void)
{
	std::cout << "After: ";
	for (size_t i = 0; i < this->_vector.size(); i++)
		std::cout << this->_vector[i] << " ";
	std::cout << std::endl;
	return ;
}

void	PmergeMe::printDuration(void)
{
	std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector: " << this->_durationVector * 1000 << " ms" << std::endl;
	std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque: " << this->_durationDeque * 1000 << " ms" << std::endl;
	return ;
}

void	PmergeMe::sortVector(void)
{
	for (std::deque<unsigned int>::iterator it = this->_unsorted.begin(); it != this->_unsorted.end(); ++it)
		this->_vector.push_back(*it);
	std::clock_t	begin = std::clock();
	for (size_t i = 0; i < this->_vector.size(); i += 2)
	{
		if (i + 1 < this->_vector.size() && this->_vector[i] > this->_vector[i + 1])
			std::swap(this->_vector[i], this->_vector[i + 1]);
	}
	for (size_t step = 2; step < this->_vector.size(); step *= 2)
	{
		for (size_t i = 0; i < this->_vector.size(); i += 2 * step)
		{
			size_t	left = i;
			size_t	right = std::min(i + step, this->_vector.size());
			size_t	end = std::min(i + 2 * step, this->_vector.size());
			std::inplace_merge(this->_vector.begin() + left, this->_vector.begin() + right, this->_vector.begin() + end);
		}
	}
	for (size_t i = 0; i < this->_vector.size(); i++)
		std::cout << this->_vector[i] << " ";
	std::cout << std::endl;
	std::clock_t	end = std::clock();
	this->_durationVector = (end - begin) / (double)CLOCKS_PER_SEC;
	return ;
}

void	PmergeMe::sortDeque(void)
{
	for (std::deque<unsigned int>::iterator it = this->_unsorted.begin(); it != this->_unsorted.end(); ++it)
		this->_deque.push_back(*it);
	std::clock_t	begin = std::clock();
	for (size_t i = 0; i < this->_deque.size(); i += 2)
	{
		if (i + 1 < this->_deque.size() && this->_deque[i] > this->_deque[i + 1])
			std::swap(this->_deque[i], this->_deque[i + 1]);
	}
	for (size_t step = 2; step < this->_deque.size(); step *= 2)
	{
		for (size_t i = 0; i < this->_deque.size(); i += 2 * step)
		{
			size_t	left = i;
			size_t	right = std::min(i + step, this->_deque.size());
			size_t	end = std::min(i + 2 * step, this->_deque.size());
			std::inplace_merge(this->_deque.begin() + left, this->_deque.begin() + right, this->_deque.begin() + end);
		}
	}
	std::clock_t	end = std::clock();
	this->_durationDeque = (end - begin) / (double)CLOCKS_PER_SEC;
	return ;
}

const char	*PmergeMe::InvalidInputException::what() const throw()
{
	return ("Invalid input! Must be a positive int!");
};

