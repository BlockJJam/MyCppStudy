/*
	��Ӱ� ����������
		-> �ڽ��� �θ� ��������� ������ �� �־���? -> ���� ������ ���� �˾ƺ���

*/

#include <iostream>
using namespace std;

class Base
{
public:
	int _public;
protected:				// private�̶� ����ϳ� ��ӹ��� Ŭ�������� ���� ��������
	int _protected;
private:
	int _private;
};

class Derived : private Base				// ������ ���������ڰ� �θ�Ŭ������ ���������ڿ� �񱳸� �ؼ� �� �������� ������ ����
{
public:
	Derived()
	{
		Base::_public;
		Base::_protected;
		Base::_private;
	}
};

class GrandChild : public Derived
{
public:
	GrandChild()
	{
		Derived::_public;
		Derived::_protected;
	}
};

int main()
{
	Derived base;

	base._public = 123;						// Derived�� ���������ڰ� Protected�̱� ������ public�� �ȵ�
	base._private = 123;
	base._protected = 123;

	return 0;
}