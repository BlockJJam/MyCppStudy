/*
	가상 소멸자
		-> 
*/

#include <iostream>
using namespace std;
class Base
{
public:
	virtual ~Base()						// virtual을 붙이면 자식클래스까지 소멸자가 작동함
	{
		cout << "~Base()" << endl;
	}
};

class Derived : public Base
{
private:
	int *_array;

public:
	Derived(int length)
	{
		_array = new int[length];
	}
	
	virtual ~Derived() override
	{
		cout << "~Derived()" << endl;
		delete[] _array;
	}
};

int main()
{
	//Derived derived(5);

	// 다형성을 사용하는 경우
	
	Derived *derived = new Derived(5);
	Base *base = derived;
	delete base;						//  Base만 delete 하게되는데, Derived에 대한 메모리누수가 생김
	return 0;
}