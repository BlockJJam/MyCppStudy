/*
	���� ����ȯ
		-> �ڽĿ��� �θ�, �θ𿡼� �ڽ����� ĳ����
		-> ���� ��� �ƴϸ� ��� X  ����
		-> functional ���, lambda ��� ���
*/

#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
	int _i = 0;

	virtual void print()
	{
		cout << "I'm base" << endl;
	}
};

class Derived1 : public Base
{
public:
	int _j = 1024;

	virtual void print() override
	{
		cout << "I'm derived1 " << endl;
	}
};

class Derived2 : public Base
{
public:
	string _name = "Dr.Tow";

	virtual void print() override
	{
		cout << "I'm derived2 " << endl;
	}
};

int main()
{
	Derived1 d1;
	Base *base = &d1;
	d1._j = 2048;

	auto *base_to_d1 = dynamic_cast<Derived1*> (base);		// ����ĳ������ �����ϸ� nullptr�� �־����
															// statice ĳ������ �ִ��� �� �� �ִ´�� �� �� 
	if (base_to_d1 != nullptr)
		base_to_d1->print();
	else
		cout << "Failed" << endl;
	
	//base_to_d1->_j = 256;

	//cout << d1._j << endl;

	return 0;
}