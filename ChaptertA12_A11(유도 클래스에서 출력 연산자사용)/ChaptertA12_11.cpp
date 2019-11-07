/*
	���� Ŭ����(�ڽ�)���� ��� ������ ����ϱ�
		-> ��� �����ڴ� �������̵��� X
		-> �������� �Բ� ��¿����ڸ� ����Ŭ����(�ڽ�)���� ����ϱ�
		-> ��¿����ڸ� �θ�Ŭ������ �����, �ٸ� �Լ��� �����ؼ�, �� �ٸ� �Լ��� virtual �ؼ� �ڽ� Ŭ������ �������̵� �Ѵ�
*/

#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{}

	friend std::ostream & operator << (std::ostream & out, const Base &b)	// member�� �ƴ϶� �������̵� X , ���� �������̵��� �ȵ�
	{
		return b.print(out);
	}

	virtual std::ostream & print(std::ostream & out) const
	{
		out << "Base";
		return out;
	}
};

class Derived : public  Base
{
public:
	Derived() {}

	virtual std::ostream & print(std::ostream & out) const override
	{
		out << "Derived";
		return out;
	}
};

int main()
{
	Base b;
	cout << b << '\n';

	Derived d;
	cout << d << '\n'; 

	Base &bref = d;
	cout << bref << '\n';

	return 0;
}