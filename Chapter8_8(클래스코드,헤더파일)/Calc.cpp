#include "Calc.h"

using namespace std;

Calc::Calc(int init_value)
	: _value(init_value)
{}

Calc& Calc::add(int value)		// 자기자신을 호출할 수 있게
{
	_value += value;
	return *this;
}

// 자기자신을 호출할 수 있게

Calc & Calc::sub(int value)
{
	_value -= value;
	return *this;
}

Calc & Calc::mul(int value)
{
	_value *= value;
	return *this;
}

void Calc::print()
{
	cout << _value << endl;
}
