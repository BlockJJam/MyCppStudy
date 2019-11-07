/*
	����� �⺻ 
		-> ��������~

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

class Child : public Mother			// Child class�� derived class
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
	Mother mother(1024);					// �θ�Ŭ������ �����ڴ� �ڽ� Ŭ������ �ҷ����� -> �⺻�����ڰ� �־���� (�Ű����� x)
	//mother.setValue(1024);
	cout << mother.getValue() << endl;

	Child child(1024, 123.123);
	/*child.Mother::setValue(1023);
	child.setValue(128);*/
	cout << child.Mother::getValue() << endl;
	cout << child.getValue() << endl;		// double



	return 0;
}