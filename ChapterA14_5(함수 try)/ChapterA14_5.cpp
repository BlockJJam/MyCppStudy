/*
	함수 try
		-> 클래스의 생성자에서 발생하는 예외를 처리하는 방식도 중요
		-> initialize list 에서 발생하는 예외 처리
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
		B b(-1);			// 생성자에서 catch하고, 생성자에서 한번더 throw를 하게 된다 -> 생성자에서 throw한 예외를 catch해줘야 함 
	}
	/*catch (...)
	{
		cout << "Catch in main()" << endl;
	}*/

	return 0;
}