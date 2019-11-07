/*
	자료형이 아닌 템플릿 매개변수
*/

#include "MyArray.h"

int main()
{
	int i = 100;
	MyArray<double, 100 > my_arr;	// MyArray<double, i> my_arr; 는 안됨 (컴파일시간에 정해져야함)

	for (int i = 0; i < my_arr.getLength(); i++)
		my_arr[i] = i + 65;

	my_arr.print();

	return 0;
}