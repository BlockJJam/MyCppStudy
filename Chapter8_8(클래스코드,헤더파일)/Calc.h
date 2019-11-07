#pragma once		// header guard

#include <iostream>

class Calc
{

private:
	int _value;

public:

	Calc(int init_value);

	Calc& add(int value);		// 자기자신을 호출할 수 있게
	Calc& sub(int value);
	Calc& mul(int value);
	void print();
};


