#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
private:									// 
	string _name;

public:
	/*Person()
		:_name("No Nmae")
	{}*/
	Person(const string & name_in="No name")
		: _name(name_in)
	{}

	void setName(const std::string & name_in)
	{
		_name = name_in;
	}

	string getName() const						// 뒤에 const로 변하지 않을 것을 선언
	{
		return _name;
	}

	void doNothing() const
	{
		cout << _name << " is doing nothing" << endl;
	}

};
