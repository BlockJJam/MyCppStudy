/*
	함수 템플릿 특수화 ( specialization )
 
*/

#include <iostream>
#include <string>
#include "Storage.h"

using namespace std;

//template <typename T>			// if문을 사용할 수 없다, 컴파일 시간에 정해져야 되기 때문 -> 특수화를 사용
//T getMax(T x, T y)
//{
//
//	return (x > y) ? x : y;
//}
//
//template<>
//char getMax(char x, char y)
//{
//	cout << "Warning : comparing chars" << endl;
//
//	return (x > y) ? x : y;
//}

int main()
{
	//cout << getMax(1, 2) << endl;
	//cout << getMax('a', 'b') << endl;

	Storage<int> nValue(5);
	Storage<double> dValue(5.5);

	nValue.print();
	dValue.print();

	return 0;
}