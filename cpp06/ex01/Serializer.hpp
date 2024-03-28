#pragma once

#ifndef Serializer_HPP
# define Serializer_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class	Serializer
{
private:
						Serializer(void);
						Serializer(const Serializer &serializer);
						~Serializer(void);

	Serializer			&operator=(const Serializer &rhs);
	
public:
	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);

};

#endif