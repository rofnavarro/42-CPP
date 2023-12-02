#pragma once

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <cstdlib>

class Converter
{
private:
	std::string		_from;
	std::string		_to;
    std::string 	_s1;
    std::string 	_s2;

	int				fileCheck(std::ifstream &from);
	std::string 	contentToString(std::ifstream &from);
	void			findAndReplace(std::string &tmp);
	void			newFile(std::ofstream &to, std::string &tmp);

public:
			Converter(std::string from, std::string s1, std::string s2);
			~Converter(void);
	void	work(void);
};

#endif