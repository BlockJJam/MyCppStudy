/*
	�Լ� ���ø�
		->  ���� ���� �ڷ����� ���ؼ� �ߺ��� �������ش�
		-> template���� ���� func�� Ư���� ������Ÿ�Կ� ���ؼ� ����� ���� instanciation
*/

#include <iostream>
#include <string>
#include "Cents.h"
using namespace std;

// template ���� �ߺ��� ������ , class �� ����


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