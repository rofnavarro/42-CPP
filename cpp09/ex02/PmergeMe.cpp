/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:36:25 by rferrero          #+#    #+#             */
/*   Updated: 2024/04/02 07:01:19 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	compairSecond(std::pair<unsigned int, unsigned int> x, std::pair<unsigned int, unsigned int> y);

PmergeMe::PmergeMe(void)
:_single(-1)
{
	return ;
}

PmergeMe::PmergeMe(const PmergeMe &pmergeme)
:_single(-1)
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
		if (i != 1 && this->isDuplicated() == true)
			throw PmergeMe::DuplicatedInputException();
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

bool	PmergeMe::isDuplicated(void)
{
	return (std::unique(this->_unsorted.begin(), this->_unsorted.end()) != this->_unsorted.end());
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
	for (size_t i = 0; i < this->_vector.size(); i ++)
		std::cout << this->_vector[i] << " ";
	std::cout << std::endl;
	return ;
}

void	PmergeMe::printDuration(void)
{
	std::cout << "Time to process a range of " << this->_unsorted.size() << " elements with std::vector: " << this->_durationVector * 1000 << " ms" << std::endl;
	std::cout << "Time to process a range of " << this->_unsorted.size() << " elements with std::deque: " << this->_durationDeque * 1000 << " ms" << std::endl;
	return ;
}

void	PmergeMe::sortVector(void)
{
	std::clock_t	begin = std::clock();
	this->pairVector();
	std::sort(this->_pairVector.begin(), this->_pairVector.end(), &compairSecond);
	for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = this->_pairVector.begin(); it < this->_pairVector.end(); it++)
		this->_vector.push_back((*it).second);
	for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = this->_pairVector.begin(); it < this->_pairVector.end(); it++)
		this->vectorInsert((*it).first);
	if (this->_single != -1)
		this->vectorInsert(this->_single);
	std::clock_t	end = std::clock();
	this->_durationVector = (end - begin) / (double)CLOCKS_PER_SEC;
	return ;
}

void	PmergeMe::pairVector(void)
{
	if (this->_unsorted.size() % 2 != 0)
	{
		this->_single = this->_unsorted.front();
		this->_unsorted.pop_front();
	}
	std::deque<unsigned int>	ref(this->_unsorted);
	unsigned int				buffer[2];
	while (ref.size() > 1)
	{
		buffer[0] = ref.front();
		ref.pop_front();
		buffer[1] = ref.front();
		ref.pop_front();
		if (buffer[0] > buffer[1])
			this->_pairVector.push_back(std::make_pair(buffer[0], buffer[1]));
		else
			this->_pairVector.push_back(std::make_pair(buffer[1], buffer[0]));
	}
	return ;
}

void	PmergeMe::vectorInsert(unsigned int num)
{
	std::vector<unsigned int>::iterator	it = std::lower_bound(this->_vector.begin(), this->_vector.end(), num);
	this->_vector.insert(it, num);
	return ;
}

void	PmergeMe::sortDeque(void)
{
	std::clock_t	begin = std::clock();
	this->pairDeque();
	std::sort(this->_pairDeque.begin(), this->_pairDeque.end(), &compairSecond);
	for (std::deque<std::pair<unsigned int, unsigned int> >::iterator it = this->_pairDeque.begin(); it < this->_pairDeque.end(); it++)
		this->_deque.push_back((*it).second);
	for (std::deque<std::pair<unsigned int, unsigned int> >::iterator it = this->_pairDeque.begin(); it < this->_pairDeque.end(); it++)
		this->dequeInsert((*it).first);
	if (this->_single != -1)
		this->dequeInsert(this->_single);
	std::clock_t	end = std::clock();
	this->_durationDeque = (end - begin) / (double)CLOCKS_PER_SEC;
	return ;
}

void	PmergeMe::pairDeque(void)
{
	if (this->_unsorted.size() % 2 != 0)
	{
		this->_single = this->_unsorted.front();
		this->_unsorted.pop_front();
	}
	std::deque<unsigned int>	ref(this->_unsorted);
	unsigned int				buffer[2];
	while (ref.size() > 1)
	{
		buffer[0] = ref.front();
		ref.pop_front();
		buffer[1] = ref.front();
		ref.pop_front();
		if (buffer[0] > buffer[1])
			this->_pairDeque.push_back(std::make_pair(buffer[0], buffer[1]));
		else
			this->_pairDeque.push_back(std::make_pair(buffer[1], buffer[0]));
	}
	return ;
}

void	PmergeMe::dequeInsert(unsigned int num)
{
	std::deque<unsigned int>::iterator	it = std::lower_bound(this->_deque.begin(), this->_deque.end(), num);
	this->_deque.insert(it, num);
	return ;
}

const char	*PmergeMe::InvalidInputException::what() const throw()
{
	return ("Invalid input! Must be a positive int!");
};

const char	*PmergeMe::DuplicatedInputException::what() const throw()
{
	return ("Invalid input! Cannot use duplicates!");
};

bool	compairSecond(std::pair<unsigned int, unsigned int> x, std::pair<unsigned int, unsigned int> y)
{
	return (x.second < y.second);
}
