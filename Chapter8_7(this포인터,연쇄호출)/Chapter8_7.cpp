/*
	this, ���� ȣ��
		-> �� �ν��Ͻ��� ��� ��������
		-> setID �Լ��� Ŭ�����ȿ� �Լ��ν� ��� ��ü�� �����ϴ� ���ε�, ��� ���ο��� ��ü���� ������ �ұ�? ��: (this->) �� �����ִ�
*/

#include <iostream>

using namespace std;

class Simple
{
private:
	int _id;
	
public:
	Simple(int id)
	{
		this->setID(id);
		this->_id;

		cout << this << endl;
	}

	void setID(int id)
	{
		_id = id;
	}

	int getID()
	{
		return _id;
	}
};

class Calc
{
private :
	int _value;

public: 
	Calc(int init_value)
		: _value(init_value)
	{}

	Calc& add(int value)		// �ڱ��ڽ��� ȣ���� �� �ְ�
	{
		_value += value;
		return *this;
	}
	Calc& sub(int value)
	{
		_value -= value;
		return *this;
	}
	Calc& mul(int value)
	{
		_value *= value;
		return *this;
	}

	void print()
	{
		cout << _value << endl;
	}
};

int main()
{
	Simple s1(1), s2(2);			// �� �ν��Ͻ��� �ڽ��� �������ּҸ� �����ִ�

	s1.setID(2);
	s2.setID(4);

	cout << &s1 << " " << &s2 << endl;

	//Simple::setID(&s2,4) -> s2.setID(4)

	// Chaining member fucntions
	Calc cal(10);
	/*cal.add(10);
	cal.sub(15);
	cal.mul(10);*/
	cal.add(10).sub(10).mul(10).print();

	return 0;
}
