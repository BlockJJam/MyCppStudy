/*
	예외처리의 위험성과 단점
		-> 예외처리하다보면 메모리처리가 안되서 누수가 발생가능
		-> 주의해야될 점: 소멸자에서는 예외처리 throw하면 안됨
		-> loop안에 예외처리 하지말자
		-> 모든 에러를 예외처리 하려고 하지말자, 정상적인 일을 처리하려고 할 때는 if문이 낫다, 예측에서 벗어나는 일이 일어날 때 예외처리하자
*/

#include <iostream>
#include <memory>
using namespace std;

class A
{
public:
	~A()
	{
		throw "Error";			// 소멸자에서는 예외처리 throw하면 안됨
	}
};

int main()
{
	try
	{
		int *i = new int[100000];
		//스마트포인터
		unique_ptr<int> up_i(i);				// 영역을 벗어나기만 하면 메모리를 알아서 처리, throw되도 처리해줌

		throw "error";

		//delete[] i;
	}
	catch (...)
	{
		cout << "Catch" << endl;
	}

	return 0;
}