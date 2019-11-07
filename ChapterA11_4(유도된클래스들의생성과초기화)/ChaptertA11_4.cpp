/*
	유도된 클래스들의 생성과 초기화
*/

#include <iostream>
using namespace std;
//
//class Mother
//{
//private:
//	int _i;
//
//	Mother(const int & i_in =0 )
//		: _i(i_in)
//	{
//		cout << " Mother construction" << endl;
//	}
//
//};
//
//class Child : public Mother
//{
//private :
//	double _d;
//
//public:
//	Child()
//		:_d(1024),Mother(1024)
//	{
//		cout << " Child construction" << endl;
//	}
//};

class A
{
public:

	A(int a)
	{
		cout << "A :" << a << endl;
	}
	~A()
	{
		cout << "destructor A" << endl;
	}
};

class B : public A
{
public:
	B(int a, double b)
		:A(a)
	{
		cout << "B : " << b << endl;
	}
	~B()
	{
		cout << "destructor B" << endl;
	}

};

class C : public B
{
public:
	C(int a, double b, char c)
		: B(a,b)
	{
		cout << "C : "<< c << endl;
	}
	~C()
	{
		cout << "destructor C" << endl;
	}
};

int main()
{
	/*Child c1;
	cout << sizeof(Mother) << endl;
	cout << sizeof(Child) << endl;
	*/
	C c(1024,1.1, 'c');

	return 0;
}