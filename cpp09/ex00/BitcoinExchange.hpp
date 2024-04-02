#pragma once

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <cstdlib>

class	BitcoinExchange
{
private:
	std::map<std::string, double>	_data;
	std::string						_csvFile;
	std::string						_inputFile;

public:
	class	CannotOpenFileException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
	class	EmptyFileException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
	class	InvalidDataCsvFormatException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
	class	InvalidDataInputFormatException: public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};


					BitcoinExchange(void);
					BitcoinExchange(std::string csvFile, std::string inputFile);
					BitcoinExchange(const BitcoinExchange &bitcoinexchange);

					~BitcoinExchange(void);

	BitcoinExchange	&operator=(const BitcoinExchange &rhs);

	void			getBitcoinData(void);
	void			getInputData(void);

	double			rate(std::string date);

	void			run(void);

};

#endif