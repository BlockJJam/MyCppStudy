/*
	상속과 접근지정자
		-> 자식이 부모 멤버변수를 접근할 수 있었나? -> 접근 범위에 대해 알아보자

*/

#include <iostream>
using namespace std;

class Base
{
public:
	int _public;
protected:				// private이랑 비슷하나 상속받은 클래스에서 접근 가능한지
	int _protected;
private:
	int _private;
};

class Derived : private Base				// 여기의 접근지정자가 부모클래스의 접근지정자와 비교를 해서 더 제한적인 범위를 따라감
{
public:
	Derived()
	{
		Base::_public;
		Base::_protected;
		Base::_private;
	}
};

class GrandChild : public Derived
{
public:
	GrandChild()
	{
		Derived::_public;
		Derived::_protected;
	}
};

int main()
{
	Derived base;

	base._public = 123;						// Derived의 접근지정자가 Protected이기 때문에 public이 안됨
	base._private = 123;
	base._protected = 123;

	return 0;
}