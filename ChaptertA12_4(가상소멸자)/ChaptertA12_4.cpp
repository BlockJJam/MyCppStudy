/*
	���� �Ҹ���
		-> 
*/

#include <iostream>
using namespace std;
class Base
{
public:
	virtual ~Base()						// virtual�� ���̸� �ڽ�Ŭ�������� �Ҹ��ڰ� �۵���
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

	// �������� ����ϴ� ���
	
	Derived *derived = new Derived(5);
	Base *base = derived;
	delete base;						//  Base�� delete �ϰԵǴµ�, Derived�� ���� �޸𸮴����� ����
	return 0;
}