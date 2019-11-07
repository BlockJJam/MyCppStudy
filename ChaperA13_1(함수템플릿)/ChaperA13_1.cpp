/*
	함수 템플릿
		->  여러 가지 자료형에 대해서 중복을 방지해준다
		-> template으로 만든 func은 특정한 데이터타입에 대해서 만드는 것을 instanciation
*/

#include <iostream>
#include <string>
#include "Cents.h"
using namespace std;

// template 으로 중복을 없애자 , class 도 가능


template<typename T> 

T getMax(T x, T y)
{
	return (x > y) ? x : y;
}


int main()
{
	cout << getMax(1, 2) << endl;
	cout << getMax(1.1, 1.2) << endl;
	cout << getMax(1.0f, 2.2f) << endl;
	cout << getMax('c', 'a') << endl;

	cout << getMax(Cents(5), Cents(9)) << endl;

	return 0;
}