/*
	override(오버라이딩), final 지정자, 공변 반환형 Covariant
*/

#include <iostream>
using namespace std;

class A
{
public:
	virtual void print(int x)				
	{
		cout << "A" << endl;
	}
	void print()
	{
		cout << "A" << endl;
	}
	virtual A* getThis() 
	{ 
		cout << "A::getThis()" << endl;
		return this;
	}
};

class B : public A
{
public:
	virtual void print (int x) override	//final		// override :오버라이딩 한 것을 명시적으로 알려준다.( const, 매개변수타입, 함수이름 등등을 체크) , final : 이 함수는 오버라이드 하지마라
	{
		cout << "B" << endl;
	}
	void print()
	{
		cout << "B" << endl;
	}
	virtual B* getThis() 
	{
		cout << "B::getThis()" << endl;
		return this; 
	}
};

class C : public B
{
public:
	virtual void print(int x)
	{
		cout << "C" << endl;
	}
};

class D : public C
{
public:
	virtual void print()						
	{
		cout << "D" << endl;
	}
};

int main()
{
	A a;
	B b;

	A &ref = b;
	b.getThis()->print();
	ref.getThis()->print();						// ref.getThis() -> B::getThis() -> A::print() 공변반환형

	cout << typeid(b.getThis()).name() << endl;
	cout << typeid(ref.getThis()).name() << endl;


	return 0;
}