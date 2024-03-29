#pragma once

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template<typename T>
class	Array
{
private:
	unsigned int	_size;
	T				*_array;

public:
	Array(void): _size(0), _array(new T[0])
	{
		return ;
	}

	Array(unsigned int size): _size(size), _array(new T[size])
	{
		return ;
	}

	Array(const Array &rhs)
	{
		this->_size = rhs._size;
		this->_array = new T[rhs._size];
		for (unsigned int counter = 0; counter < rhs._size; counter++)
			this->_array[counter] = rhs._array[counter];
		return ;
	}

	~Array(void)
	{
		delete [] this->_array;
		return ;
	}

	Array	&operator=(const Array &rhs)
	{
		if (this != &rhs)
		{
			this->~Array();
			this->_size = rhs._size;
			this->_array = new T[rhs._size];
			for (unsigned int counter = 0; counter < rhs._size; counter++)
				this->_array[counter] = rhs._array[counter];
		}
		return (*this);
	}

	T	&operator[](unsigned int index)
	{
		if (index >= this->_size)
			throw std::out_of_range("Invalid index");
		return (this->_array[index]);
	}

	unsigned int	size(void) const
	{
		return (this->_size);
	}

};

#endif