/*
	예외 클래스와 상속
		->
*/

#include <iostream>
using namespace std;

// 예외 클래스
class Exception								
{
public:
	void report()
	{
		cerr << "Exception report " << endl;
	}
};

// 상속 예외클래스
class ArrayException : public Exception
{
public:
	void report()
	{
		cerr << "Array exception" << endl;
	}
};

class MyArray
{
private:
	int _data[5];

public:
	int & operator [] (const int & index)
	{
		if (index < 0 || index >= 5) 
			throw ArrayException();

		return _data[index];
	}
};

void doSomething()
{
	MyArray my_array;

	try
	{
		my_array[100];
	}
	catch (const int & x)
	{
		cerr << "Exception " << x << endl;
	}
	//catch (ArrayException & e)
	//{
	//	cout << "doSomething()" << endl;
	//	e.report();
	//	throw e;							// re-throw를 하면 그 Stack rewind로 뒤 순서의 catch가 잡힌다
	//}
	catch (Exception & e)					// 객체잘림 현상
	{
		cout << "doSomething()" << endl;
		e.report();
		//throw e;							// 그냥 throw를 하면?
		throw;
	}
}

int main()
{
	try
	{
		doSomething();
	}
	catch (ArrayException & e)
	{
		cout << "main()" << endl;
		e.report();
	}
	catch (Exception & e)
	{
		cout << "main() " << endl;
		e.report();
	}
	

	return 0;
}