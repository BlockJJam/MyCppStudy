#pragma once

#include <iostream>
template <class T>

class Storage
{
private:
	T _value;

public:
	Storage(T value)
	{
		_value = value;
	}

	~Storage()
	{}

	void print()
	{
		std::cout << _value << std::endl;
	}
};

template<>							// specialization을 한 것은 cpp말고 header파일에 냅두자 (1)
void Storage<double>::print()
{
	std::cout << "double Type ";
	std::cout << std::scientific << _value << std::endl;
}

