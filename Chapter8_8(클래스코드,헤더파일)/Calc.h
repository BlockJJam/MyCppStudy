#pragma once		// header guard

#include <iostream>

class Calc
{

private:
	int _value;

public:

	Calc(int init_value);

	Calc& add(int value);		// �ڱ��ڽ��� ȣ���� �� �ְ�
	Calc& sub(int value);
	Calc& mul(int value);
	void print();
};


