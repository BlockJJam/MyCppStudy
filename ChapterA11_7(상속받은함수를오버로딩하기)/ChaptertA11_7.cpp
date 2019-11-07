/*
	상속받는 함수를 오버라이딩 하기
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

class Derived : public Base					// Derived 의 print()와 Base의 print()를 같은 이름을 짓고 싶을 때
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
		cout << static_cast<Base>(d);							// 왜 캐스팅이 될까?  derived가 메모리에 base의 주소를 담고 있기 때문에(base를 생성하니까)
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