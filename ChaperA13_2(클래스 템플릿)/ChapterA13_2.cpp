/*
	Class Template
		-> 헤더파일에 선언부를 남기고, 정의를 cpp 파일로 빼내면 링킹 에러가 뜸
		-> main -> 헤더 -> cpp 까지 가서 타입을 찾아내지를 못함
*/

#include "MyArray.h"

int main()
{
	MyArray<double> my_arr(10);

	for (int i = 0; i < my_arr.getLength(); i++)
		my_arr[i] = i * 0.5;

	my_arr.print();

	return 0;
}