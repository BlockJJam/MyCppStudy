/*
	��ü�߸��� reference wrraper
		��ü�߸� -> ���� ��ü�� ū �ڽİ�ü�� ������ �� �� ����� ����
		reference wrapper -> ��ü�߸� ������ �������� ���
*/

#include <iostream>
#include <vector>
#include <functional>			// functional -> reference_wrapper

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

class Derived : public Base
{
public:
	int _j = 1;

	virtual void print() override
	{
		cout << "I'm derived " << endl;
	}
};

void doSomething(Base &b)			// & b�� �ƴ� �׳� b�� ��, ������ ���ָ� �׳� Base ��ü�� ����
{
	b.print();
}

int main()
{
	//Derived d;
	////Base &b = d;
	//Base b = d;			// �������� ��������, d ��ü�� �׳� ����

	//b.print();

	//doSomething(d);

	Base b;
	Derived d;

	std::vector<reference_wrapper<Base>> my_vec;		// = vector<Base&> my_vec; 
												// my_vec�� Base�� ������ ��� ���Ͷ�� �ǹ�
	my_vec.push_back(b);
	my_vec.push_back(d);

	for (auto & ele : my_vec)
		ele.get().print();

	return 0;
}