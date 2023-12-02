/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rferrero <rferrero@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:19:32 by rferrero          #+#    #+#             */
/*   Updated: 2023/12/01 20:59:29 by rferrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

Converter::Converter(std::string from, std::string s1, std::string s2)
:_from(from), _s1(s1), _s2(s2)
{
	this->_to = from + ".replace";
	return ;
}

Converter::~Converter()
{
	return ;
}

void	Converter::work()
{
	std::ifstream	from(this->_from.c_str());
	std::string		tmp;

	if (this->fileCheck(from) == 1)
		return ;
	std::ofstream	to((this->_to).c_str());
	tmp = this->contentToString(from);
	this->findAndReplace(tmp);
	this->newFile(to, tmp);
	return ;
}

int	Converter::fileCheck(std::ifstream &from)
{
	if (!from.is_open() || from.fail())
	{
		std::cerr << "Invalid filename" <<std::endl;
		from.close();
		return (1);
	}
	return (0);
}

std::string	Converter::contentToString(std::ifstream &from)
{
    std::ostringstream	tmp;
	std::string 		ret;

    tmp << from.rdbuf();
    ret = tmp.str();
    from.close();
    return (ret);
}

void	Converter::findAndReplace(std::string &tmp)
{
	std::size_t	found;

	found = 0;
    while ((found = tmp.find(this->_s1, found)) != std::string::npos)
    {
        if (tmp.empty())
            std::cerr << "It appears you have submitted an empty file." << std::endl;
        tmp.erase(found, (this->_s1).length());
        tmp.insert(found, this->_s2);
        found += (this->_s2).length();
    }
	return ;
}

void	Converter::newFile(std::ofstream &to, std::string &tmp)
{
	to << tmp;
	to.close();
}
