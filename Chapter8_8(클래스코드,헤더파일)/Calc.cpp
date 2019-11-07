#include "Calc.h"

using namespace std;

Calc::Calc(int init_value)
	: _value(init_value)
{}

Calc& Calc::add(int value)		// �ڱ��ڽ��� ȣ���� �� �ְ�
{
	_value += value;
	return *this;
}

// �ڱ��ڽ��� ȣ���� �� �ְ�

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
