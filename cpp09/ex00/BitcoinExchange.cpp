/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 20:19:44 by rferrero          #+#    #+#             */
/*   Updated: 2024/04/02 09:24:06 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool	isDateValid(std::string date);

BitcoinExchange::BitcoinExchange(void)
{
	return ;
}

BitcoinExchange::BitcoinExchange(std::string csvFile, std::string inputFile)
:_csvFile(csvFile), _inputFile(inputFile)
{
	return ;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinexchange)
{
	*this = bitcoinexchange;
	return ;
}

BitcoinExchange::~BitcoinExchange(void)
{
	return ;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		this->_csvFile = rhs._csvFile;
		this->_inputFile = rhs._inputFile;
		this->_data = rhs._data;
	}
	return (*this);
}

void	BitcoinExchange::getBitcoinData(void)
{
	std::ifstream	data;
	std::string		line;
	double			value;

	data.open(this->_csvFile.c_str());
	if (!data.is_open())
		throw	BitcoinExchange::CannotOpenFileException();
	if (data.peek() == std::ifstream::traits_type::eof())
		throw	BitcoinExchange::EmptyFileException();
	std::getline(data, line);
	while (getline(data, line))
	{
		std::istringstream	input;
		std::string			date;

		input.str(line);
		getline(input, date, ',');
		input >> value;
		this->_data.insert(std::pair<std::string, double>(date, value));
	}
	return ;
}

void	BitcoinExchange::getInputData(void)
{
	std::ifstream	data;
	std::string		line;

	data.open(this->_inputFile.c_str());
	if (!data.is_open())
		throw	BitcoinExchange::CannotOpenFileException();
	if (data.peek() == std::ifstream::traits_type::eof())
		throw	BitcoinExchange::EmptyFileException();
	std::getline(data, line);
	if (line != "date | value")
		throw	BitcoinExchange::InvalidDataCsvFormatException();
	while (getline(data, line))
	{
		std::string		date;
		std::string		pipe = " | ";
		std::string		str_value;
		double			value;
		size_t			position = line.find(pipe);

		if (position == 10)
		{
			date = line.substr(0, position);
			str_value = line.substr(position + pipe.length());
		}
		else
		{
			date = line;
			str_value = "";
		}
		value = std::strtod(str_value.c_str(), NULL);
	
		if (!value)
			std::cout << "Error: empty value or invalid format." << std::endl;
		else if (value < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (position != 10 || isDateValid(date) == false)
			std::cout << "Error: bad input => " << date << std::endl;
		else if (value > 1000)
			std::cout << "Error: too large number." << std::endl;
		else
			std::cout << date << " => " << value << " = " << value * rate(date) << std::endl;
	}
	return ;
}

double	BitcoinExchange::rate(std::string date)
{
	std::map<std::string, double>::const_iterator it = this->_data.lower_bound(date);

	if(it != this->_data.begin() && it->first != date)
		return ((--it)->second);
	return (it->second);
}

static bool	isDateValid(std::string date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);

	int	year = std::atoi(date.substr(0, 4).c_str());
	if (year < 2009 || year > 2023)
		return (false);

	int	month = std::atoi(date.substr(5, 2).c_str());
	if (month < 1 || month > 12)
		return (false);

	int	day = std::atoi(date.substr(8, 2).c_str());
	if (day < 1 || day > 31)
		return (false);
	if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
		return (false);
	if (month == 2)
    {
        if (day > 29)
            return (false);
        if (day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)))
            return (false);
    }
	return (true);
}

void	BitcoinExchange::run(void)
{
	this->getBitcoinData();
	this->getInputData();
	return ;
}

const char	*BitcoinExchange::CannotOpenFileException::what() const throw()
{
	return ("File not opened!");
}

const char	*BitcoinExchange::EmptyFileException::what() const throw()
{
	return ("File is empty!");
}

const char	*BitcoinExchange::InvalidDataCsvFormatException::what() const throw()
{
	return ("Invalid data on csv file!");
}
