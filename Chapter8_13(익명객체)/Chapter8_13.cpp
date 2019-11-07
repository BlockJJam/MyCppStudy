/*
	�͸�ü -> L-value�� �ƴ� R-value ó�� ������ �Ѵ�
*/

#include <iostream>

using namespace std;

class A
{
public:
	int _value;

	A(const int& intput)
		: _value(intput)
	{
		cout << "Constructor" << endl;
	}

	~A()
	{
		cout << "Destructor" << endl;
	}

	void printDouble()
	{
		cout << _value *2 << endl;
	}
};

class Cents
{
private:
	int _cents;

public:
	Cents(int cents) { _cents = cents; }

	int getCents() const { return _cents; }
};

Cents add(const Cents &c1, const Cents &c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

int main()
{
	A a(1);
	//a.print();

	//�͸�ü
	//A().print();			// print�� ���� �����ϴµ� ���ŷӰ� ��ü�� �����ϰ� �Լ��� �θ� �ʿ� X
	//A().print();			// �̷��� �θ� ������ ������,�Ҹ��ڰ� ó����, �� ��ü�� �����Ѵ�
	//a.printDouble();
	//A(1).printDouble();

	cout << add(Cents(6), Cents(8)).getCents() << endl;
	cout << int(6) + int(8) << endl;

	return 0;
}
