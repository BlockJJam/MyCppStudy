/*
	������ Ŭ������ ���� ����
*/

#include <iostream>
using namespace std;

//class Mother
//{
//public:
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
//public:
//	int _d;
//
//	Child()
//		:_d(1024),Mother(1024)
//	{
//		cout << " Child construction" << endl;
//	}
//};

//���̸� �� �� �ְ�
class A
{
public :
	A()
	{
		cout << "A constructor" << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "B constructor" << endl;
	}
};

class C : public B
{
public:
	C()
	{
		cout << "C constructor" << endl;
	}
};
int main()
{
	//Child child;
	C a;

	return 0;
}