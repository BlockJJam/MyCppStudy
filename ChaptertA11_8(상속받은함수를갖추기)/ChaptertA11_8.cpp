/*
	��ӹ��� �Լ��� ���߱�
*/

#include <iostream>
using namespace std;

class Base
{
protected:
	int _i;

public:
	Base(int value)
		: _i(value)
	{}

	void print()
	{
		cout << " i'm base " << endl;
	}

	friend std::ostream & operator << (std::ostream & out, const Base &b)
	{
		out << " this is base output " << endl;
		return out;
	}
};

class Derived : public Base					// Derived �� print()�� Base�� print()�� ���� �̸��� ���� ���� ��
{
private:
	double _d;

public:
	Derived(int value)
		:Base(value)
	{}

	using Base::_i;							// ��ӹ��� Ŭ�������� using�� ����ؼ� �θ�Ŭ������ ��������� ��ӹ��� Ŭ������ ���������ڷ� ��밡��
	void print() = delete;					// ���� ��� (2)
private:
	using Base::print;						// ���� ��� (1) private : using Base::print;
	
};

int main()
{
	Derived derived(7);

	derived.print();						// �θ��� print()�� ���� ���ϰ�!
	

	return 0;
}