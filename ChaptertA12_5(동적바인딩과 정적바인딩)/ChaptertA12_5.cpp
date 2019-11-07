/*
	동적바인딩과 정적바인딩
*/

#include <iostream>
using namespace std;

int add(int x, int y)
{
	return x + y;
}

int sub(int x, int y)
{
	return x - y;
}

int mul(int x, int y)
{
	return x * y;
}

int main()
{
	int op;
	cin >> op;

	int x = 2, y = 3;

	int result;

	// 정적바인딩	-> 성능 우수
	switch (op)
	{
	case 0:
		result = add(x, y);
		break;
	case 1:
		result = sub(x, y);
		break;
	case 2:
		result = mul(x, y);
		break;
	default:
		break;
	}
	cout << result << endl;


	// 동적 바인딩	-> 프로그램 유연성 우수
	int(*func_ptr) (int, int) = nullptr;
	switch (op)
	{
	case 0:
		func_ptr = add;
		break;
	case 1:
		func_ptr = sub;
		break;
	case 2:
		func_ptr = mul;
		break;
	default :
		break;
	}
	cout << func_ptr(x, y) << endl;

	return 0;
}