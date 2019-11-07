/*
	가상함수와 다형성
		-> virtual 은 스택과 힙이 아닌, 호출 테이블에서 이름을 찾아가는 키워드라 되게 무겁다

*/

#include <iostream>
using namespace std;

class A
{
public:
	virtual void print()				// 가장 상위 클래스의 함수가 virtual 가상함수라면 자식 클래스들은 virtual을 이어받는다. -> 관습적으로 자식 클래스도 virtual을 해준다
	{
		cout << "A" << endl;
	}
};

class B : public A
{
public:
	virtual void print()
	{
		cout << "B" << endl;
	}
};

class C : public B
{
public:
	virtual void print()
	{
		cout << "C" << endl;
	}
};

class D : public C
{
public:
	virtual int print()						// return 타입이 다르면 error, 부모클래스와 다르면 안된다
	{
		cout << "D" << endl;
		return 0;
	}
};

int main()
{
	A a;
	B b;
	C c;
	D d;

	B &ref = c;				
	ref.print();

	return 0;
}