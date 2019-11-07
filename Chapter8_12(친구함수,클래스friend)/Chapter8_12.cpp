/*
	친구함수와 친구클래스 <friend>
*/
#include <iostream>
using namespace std;

class A;										// 전방선언

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

	friend void doSomething(A& a, B& b);		// B의 존재를 알아야 한다

	friend class B;								// B 친구에게 모든 걸 열어주고 싶을 때
	friend void B::doSomething_A(A& a);			// B 친구에게 특정 func에만 열어주고 싶을 때

};

void B::doSomething_A(A& a)						// class 전방선언 순서에 따라서 A -> B를 알고, B -> A를 알아야 할 때를 대비
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
