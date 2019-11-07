/*
	함수 포인터
		-> 함수도 포인터다( 메모리주소가 있다)

*/
#include <iostream>
#include <array>
#include <functional>		// c++ 17 더 쉬운 함수포인터 조작

using namespace std;

int func(int x)
{
	return 5;
}

int goo(int x)
{
	return 10;
}

bool isEven(const int &number)
{
	if (number % 2 == 0) return true;

}

bool isOdd(const int &number)
{
	if (number % 2 == 1) return true;

}

// 함수 포인터가 빈번하게 사용된다면 typedef를 쓰는게 좋다
//typedef bool(*check_fcn_t)(const int&);
using check_fcn_t = bool(*)(const int&);

void printNumbers(const array<int, 10> &my_array, function<bool(const int&)> check_fcn)	// array참조, 함수포인터
{
	for (auto element : my_array)
	{
		if(check_fcn(element) ==true)cout << element;
		//if (!print_even && element % 2 == 1) cout << element;
	}
	cout << endl;
}



int main()
{
	// 함수포인터 선언
	int(*fcnptr)(int) = func;
	
	cout << fcnptr(1) << endl;

	fcnptr = goo;

	cout << fcnptr(2) << endl;
	
	
	array<int, 10> my_array{ 0,1,2,3,4,5,6,7,8,9 };

	printNumbers(my_array, isEven);
	printNumbers(my_array, isOdd);

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	// functional lib 사용
	function<bool(const int&)> fcnptr2 = isEven;

	printNumbers(my_array, fcnptr2);

	fcnptr2 = isOdd;

	printNumbers(my_array, fcnptr2);

	return 0;
}