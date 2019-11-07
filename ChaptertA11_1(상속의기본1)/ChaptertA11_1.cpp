/*
	상속의 기본 
		-> 문법부터~

*/

#include <iostream>
using namespace std;

class Mother
{
private: 
	int _i;

public:
	Mother()
		:_i(0)
	{}

	Mother(const int & i_in)
		: _i(i_in)
	{
		cout << "Mother constructor " << endl;
	}

	void setValue(const int& i_in)
	{
		_i = i_in;
	}

	int getValue()
	{
		return _i;
	}
};

class Child : public Mother			// Child class를 derived class
{
private:
	double _d;

public:
	Child(const int & i_in, const double & d_in)
		//:_i(i_in), _d(d_in)
		:Mother(i_in), _d(d_in)
		{}

	void setValue(const int & i_in, const double & d_in)
	{
		Mother::setValue(i_in);
		_d = d_in;
	}

	void setValue(const double & d_in)
	{
		_d = d_in;
	}
	
	double getValue()
	{
		return _d;
	}
};

class Daughter : public Mother
{

};

class Son : public Mother
{

};

int main()
{
	Mother mother(1024);					// 부모클래스의 생성자는 자식 클래스가 불러낸다 -> 기본생성자가 있어야함 (매개변수 x)
	//mother.setValue(1024);
	cout << mother.getValue() << endl;

	Child child(1024, 123.123);
	/*child.Mother::setValue(1023);
	child.setValue(128);*/
	cout << child.Mother::getValue() << endl;
	cout << child.getValue() << endl;		// double



	return 0;
}