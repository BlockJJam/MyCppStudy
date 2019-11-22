/*
	��ӹ޴� �Լ��� �������̵� �ϱ�
*/

#include <iostream>
using namespace std;

class Base
{
protected:
	int _i;

public:
	Base(int value)
		: _i(value)
	{}

	void print()
	{
		cout << " i'm base " << endl;
	}

	friend std::ostream & operator << (std::ostream & out, const Base &b)
	{
		out << " this is base output " << endl;
		return out;
	}
};

class Derived : public Base					// Derived �� print()�� Base�� print()�� ���� �̸��� ���� ���� ��
{
private:
	double _d;

public:
	Derived(int value)
		:Base(value)
	{}

	void print()
	{
		Base::print();
		cout << " i'm derived " << endl;
	}

	friend std::ostream & operator << (std::ostream & out, const Derived &d)
	{
		cout << static_cast<Base>(d);							// �� ĳ������ �ɱ�?  derived�� �޸𸮿� base�� �ּҸ� ��� �ֱ� ������(base�� �����ϴϱ�)
		out << " this is derived output " << endl;
		return out;
	}
};


int main()
{
	Base base(5);
	//base.print();
	cout << base;

	Derived derived(7);
	//derived.print();
	cout << derived;
	return 0;
}