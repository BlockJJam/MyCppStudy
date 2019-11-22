/*
	상속받은 함수를 감추기
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

	using Base::_i;							// 상속받은 클래스에서 using을 사용해서 부모클래스의 멤버변수를 상속받은 클래스의 접근지정자로 사용가능
	void print() = delete;					// 막는 방법 (2)
private:
	using Base::print;						// 막는 방법 (1) private : using Base::print;
	
};

int main()
{
	Derived derived(7);

	derived.print();						// 부모의 print()를 접근 못하게!
	

	return 0;
}