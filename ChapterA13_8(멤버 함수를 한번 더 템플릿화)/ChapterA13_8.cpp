/*
	멤버함수를 한번 더 템플릿화
*/

#include <iostream>
#include <string>
using namespace std;

template <class T>
class A
{
private:
	T _value;
	
public:
	A(const T & input)
		:_value(input)
	{}

	template<typename TT>
	void doSomething(const TT & input)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
		cout << (TT)_value << endl;
	}
	
	void print()
	{
		cout << _value << endl;
	}
};

int main()
{
	A<char> a_int('a');
	a_int.print();

	a_int.doSomething<int>(1.12);

	return 0;
}