#include <iostream>
/*

< 함수에 대해 >

C++은 함수 안에서 함수를 정의가 안됨 ( 파이썬, 자바스크립트는 가능 )

int a()
{
	int b()
	{

	}
}


*/
using namespace std;

int multiTwoNumbers(int num_a, int num_b)
{
	int sum = num_a * num_b;

	return sum;
}

void printHelloWorld()
{
	cout << "hello World! " << endl;

	return;
}
int main()
{
	int sum = multiTwoNumbers(1, 2);
	cout << multiTwoNumbers(1, 2) << endl;
	cout << multiTwoNumbers(1, 3) << endl;
	cout << multiTwoNumbers(1, 4) << endl;

	printHelloWorld();
	return 0;
}