// 메인함수보다 위에 선언하면 가독성이 떨어지고, 메인함수보다 아래 선언하면 컴파일이 안될때
// foward declaration ( 전방선언 )을 이용해서 이름만 위로 올리자


#include <iostream>

using namespace std;

//declaration
int add(int a, int b);
int multiply(int a, int b);
int subtract(int a, int b);

int main()
{
	cout << add(1, 2) << endl;
	cout << multiply(2, 3) << endl;

	return 0;
}

//definition
int add(int a, int b)
{
	return a + b;
}

int multiply(int a, int b)
{
	return a * b;
}

int subtract(int a, int b)
{
	return a - b;
}


