/*
	유도 클래스(자식)에서 출력 연산자 사용하기
		-> 출력 연산자는 오버라이딩이 X
		-> 다형성과 함께 출력연산자를 유도클래스(자식)에서 사용하기
		-> 출력연산자를 부모클래스에 만들고, 다른 함수에 위임해서, 그 다른 함수를 virtual 해서 자식 클래스에 오버라이딩 한다
*/

#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{}

	friend std::ostream & operator << (std::ostream & out, const Base &b)	// member가 아니라서 오버라이딩 X , 직접 오버라이딩이 안됨
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