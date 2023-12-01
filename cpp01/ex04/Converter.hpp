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

	void			handler();
	std::string 	contentToString();

public:
	Converter(std::ifstream from, std::string s1, std::string s2);
	~Converter();
	int	fileCheck();
};

#endif