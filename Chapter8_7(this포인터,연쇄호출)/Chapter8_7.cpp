/*
	this, 연쇄 호출
		-> 각 인스턴스를 어떻게 구별할지
		-> setID 함수는 클래스안에 함수로써 모든 객체가 공유하는 것인데, 어떻게 내부에서 객체마다 구별을 할까? 답: (this->) 가 숨어있다
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

	Calc& add(int value)		// 자기자신을 호출할 수 있게
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
	Simple s1(1), s2(2);			// 각 인스턴스는 자신의 포인터주소를 갖구있다

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
