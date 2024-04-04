#pragma once

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <algorithm>
# include <ctime>

class	PmergeMe
{
private:
	std::deque<unsigned int>							_unsorted;
	double												_durationVector;
	std::vector<unsigned int>							_vector;
	double												_durationDeque;
	std::deque<unsigned int>							_deque;

public:
	class	InvalidInputException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

				PmergeMe(void);
				PmergeMe(const PmergeMe &pmergeme);

				~PmergeMe(void);

	PmergeMe	&operator=(const PmergeMe &rhs);

	void		getInput(char **input);

	void		run(char **input);

	void		sortVector(void);
	void		sortDeque(void);

	void		printBefore(void);
	void		printAfter(void);
	void		printDuration(void);

};

#endif