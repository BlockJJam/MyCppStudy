/*
	익명객체 -> L-value가 아닌 R-value 처럼 동작을 한다
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

	//익명객체
	//A().print();			// print를 거의 사용안하는데 번거롭게 객체를 생성하고 함수를 부를 필요 X
	//A().print();			// 이렇게 부를 때마다 생성자,소멸자가 처리됨, 즉 객체를 생성한다
	//a.printDouble();
	//A(1).printDouble();

	cout << add(Cents(6), Cents(8)).getCents() << endl;
	cout << int(6) + int(8) << endl;

	return 0;
}
