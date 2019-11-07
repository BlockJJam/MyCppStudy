/*
	�����Լ��� ������
		-> virtual �� ���ð� ���� �ƴ�, ȣ�� ���̺��� �̸��� ã�ư��� Ű����� �ǰ� ���̴�

*/

#include <iostream>
using namespace std;

class A
{
public:
	virtual void print()				// ���� ���� Ŭ������ �Լ��� virtual �����Լ���� �ڽ� Ŭ�������� virtual�� �̾�޴´�. -> ���������� �ڽ� Ŭ������ virtual�� ���ش�
	{
		cout << "A" << endl;
	}
};

class B : public A
{
public:
	virtual void print()
	{
		cout << "B" << endl;
	}
};

class C : public B
{
public:
	virtual void print()
	{
		cout << "C" << endl;
	}
};

class D : public C
{
public:
	virtual int print()						// return Ÿ���� �ٸ��� error, �θ�Ŭ������ �ٸ��� �ȵȴ�
	{
		cout << "D" << endl;
		return 0;
	}
};

int main()
{
	A a;
	B b;
	C c;
	D d;

	B &ref = c;				
	ref.print();

	return 0;
}