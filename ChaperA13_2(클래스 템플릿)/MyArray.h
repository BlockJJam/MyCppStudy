#pragma once

#include <assert.h>
#include <iostream>

template <typename T> 

class MyArray
{
private:
	int _length;
	T *_data;

public:
	MyArray()
	{
		_length = 0;
		_data = nullptr;
	}

	MyArray(int length)
	{
		_data = new T [length];
		_length = length;
	}
	~MyArray()
	{
		reset();
	}

	void reset()
	{
		delete[] _data;
		_data = nullptr;
		_length = 0;
	}

	T & operator [] (int index)
	{
		assert(index >= 0 && index < _length);
		return _data[index];
	}

	int getLength()
	{
		return _length;
	}

	void print();
};


