#pragma once
#include <iostream>

using namespace std;

class Resource
{
	//private:
public:
	int _data[100];

public:
	Resource()
	{
		cout << "Resource constructed" << endl;
	}

	~Resource()
	{
		cout << "Resource destructed" << endl;
	}
};