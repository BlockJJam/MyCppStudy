#include <iostream>
#include "MY_CONSTANTS.h"
#define PRICE_PER_ITEM 30

using namespace std;

void printNumber(const int my_number)	// 파라미터에 들어온 매개변수를 함수 안에서 바꾸는 일은 드물다
{
	int n = my_number;
	cout << n << endl;
}

int main()
{
	/*const double gravity{ 9.8 }; 
	printNumber(123);*/

	const int my_const(123);					// 컴파일 타임 상수
	constexpr int my_const2(123);				// 명시적으로 컴파일타임에 상수를 선언하겠다
	int number;
	cin >> number;
	const int special_number(number);			// 런타임 상수

	int num_item = 123;
	int price = num_item * PRICE_PER_ITEM;		// 매크로는 잘 안쓴다 1. 디버깅이 힘듬 2. 영향범위가 너무 크다

	const int price_per_item = 30;

	double radius = 1.3;
	double circumference = 2.0 * radius * constants::pi; // 상수를 사용하려면 헤더파일로 만들어서 사용해도 좋다


	return 0;
}