/*
	ģ���Լ��� ģ��Ŭ���� <friend>
*/
#include <iostream>
using namespace std;

class A;										// ���漱��

class B
{
private:
	int _value = 2;

	friend void doSomething(A& a, B& b);

public:
	void doSomething_A(A& a);
};

class A
{
private: 
	int _value = 1;

	friend void doSomething(A& a, B& b);		// B�� ���縦 �˾ƾ� �Ѵ�

	friend class B;								// B ģ������ ��� �� �����ְ� ���� ��
	friend void B::doSomething_A(A& a);			// B ģ������ Ư�� func���� �����ְ� ���� ��

};

void B::doSomething_A(A& a)						// class ���漱�� ������ ���� A -> B�� �˰�, B -> A�� �˾ƾ� �� ���� ���
{
	cout << a._value << endl;
}


void doSomething(A& a,B& b)
{
	cout << a._value <<" " <<b._value << endl;
}

int main()
{
	A a;
	B b;
	doSomething(a, b);
	b.doSomething_A(a);
	return 0;
}
