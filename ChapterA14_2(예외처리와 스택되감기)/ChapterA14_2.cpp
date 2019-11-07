/*
	예외처리와 스택되감기
*/

#include <iostream>
using namespace std;

//void last() throw(int) exception specifier
void last() throw()							// throw 안이 비어있다면 예외가 X는 표현
{
	cout << "last " << endl;
	cout << "Throws Exception" << endl;

	throw  'a';

	cout << "End last " << endl;
}

void third()
{
	cout << "Third" << endl;
	
	last();
	
	cout << " End Third " << endl;
}

void second()
{
	cout << "Second" << endl;

	try
	{
		third();
	}
	catch (double)
	{
		cerr << "second caught int exception" << endl;
	}
	cout << "End Second" << endl;
}

void first()
{
	cout << "first" << endl;
	
	try
	{
		second();
	}
	catch (int)
	{
		cerr << "first caught int exception" << endl;
	}

	cout << "End first" << endl;
}

int main()
{
	cout << "start" << endl;

	try
	{
		first();
	}
	catch (int)
	{
		cerr << "main caught int exception" << endl;
	}
	// uncauhth exception
	catch (...)
	{
		cerr << "main cautht elipse exception" << endl;
	}
	cout << "End Main" << endl;

	return 0;
}