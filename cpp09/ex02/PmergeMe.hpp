#pragma once

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <utility>
# include <algorithm>
# include <ctime>

class	PmergeMe
{
private:
	int													_single;
	std::deque<unsigned int>							_unsorted;
	double												_durationVector;
	std::vector<unsigned int>							_vector;
	std::vector<std::pair<unsigned int, unsigned int> >	_pairVector;
	double												_durationDeque;
	std::deque<unsigned int>							_deque;
	std::deque<std::pair<unsigned int, unsigned int> >	_pairDeque;

public:
	class	InvalidInputException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
	class	DuplicatedInputException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

				PmergeMe(void);
				PmergeMe(const PmergeMe &pmergeme);

				~PmergeMe(void);

	PmergeMe	&operator=(const PmergeMe &rhs);

	void		getInput(char **input);
	bool		isDuplicated(void);

	void		printBefore(void);
	void		printAfter(void);
	void		printDuration(void);

	void		run(char **input);

	void		sortVector(void);
	void		pairVector(void);
	void		vectorInsert(unsigned int num);

	void		sortDeque(void);
	void		pairDeque(void);
	void		dequeInsert(unsigned int num);

};

#endif