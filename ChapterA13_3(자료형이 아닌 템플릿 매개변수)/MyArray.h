#pragma once

#include <assert.h>
#include <iostream>

template <typename T, unsigned int T_SIZE>

class MyArray
{
private:
	/*int _length;*/
	T *_data;

public:
	MyArray()
	{
		_data = new T[T_SIZE];
	}

	~MyArray()
	{
		delete[] _data;
	}

	T & operator [] (int index)
	{
		assert(index >= 0 && index < T_SIZE);
		return _data[index];
	}

	int getLength()
	{
		return T_SIZE;
	}

	void print()
	{
		for (int i = 0; i < T_SIZE; i++)
			std::cout << _data[i] << " ";
		std::cout << std::endl;
	}
};


