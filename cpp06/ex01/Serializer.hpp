#pragma once

#ifndef Serializer_HPP
# define Serializer_HPP

class	Serializer
{
private:
					Serializer(void);
					Serializer(const Serializer &serializer);
					~Serializer(void);

	Serializer	&operator=(const Serializer &rhs);
	
public:
	static void		convert(const std::string &input);
};

#endif