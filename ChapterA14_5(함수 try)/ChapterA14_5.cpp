/*
	�Լ� try
		-> Ŭ������ �����ڿ��� �߻��ϴ� ���ܸ� ó���ϴ� ��ĵ� �߿�
		-> initialize list ���� �߻��ϴ� ���� ó��
*/

#include <iostream>
using namespace std;

class A
{
private:
	int _x;
public:
	A(int x) 
		:_x(x)
	{
		if (x <= 0)
			throw 1;
	}
};

class B : public A
{
public:
	/*B(int x)
		:A(x)
	{}*/
	
	B(int x) try : A(x)
	{
		// do initialization
	}
	catch (...)					
	{
		cout << "Catch in B constructor" << endl;
		//throw;
	}
};

//void doSomething()
//{
//	try
//	{
//		throw - 1;
//	}
//	catch (...)
//	{
//		cout << "Catch in doSomthing() " << endl;
//	}
//}

int main()
{
	try
	{
		//doSomething();
		B b(-1);			// �����ڿ��� catch�ϰ�, �����ڿ��� �ѹ��� throw�� �ϰ� �ȴ� -> �����ڿ��� throw�� ���ܸ� catch����� �� 
	}
	/*catch (...)
	{
		cout << "Catch in main()" << endl;
	}*/

	return 0;
}