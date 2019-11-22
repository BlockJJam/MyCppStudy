/*
	override(�������̵�), final ������, ���� ��ȯ�� Covariant
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
	virtual void print (int x) override	//final		// override :�������̵� �� ���� ��������� �˷��ش�.( const, �Ű�����Ÿ��, �Լ��̸� ����� üũ) , final : �� �Լ��� �������̵� ��������
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
	ref.getThis()->print();						// ref.getThis() -> B::getThis() -> A::print() ������ȯ��

	cout << typeid(b.getThis()).name() << endl;
	cout << typeid(ref.getThis()).name() << endl;


	return 0;
}