/*
	괄호연산자 오버로딩과 함수객체( Function object(Functor) )
		-> 클래스 객체를 함수 객체 처럼 쓰도록
*/

#include <iostream>
using namespace std;

class Accumulator
{
private:
	int _counter = 0;

public :
	int operator() (int i)
	{
		return _counter += i;
	}
};

int main()
{
	Accumulator acc;
	cout << acc(10) << endl;
	cout << acc(20) << endl;

	return 0;
}