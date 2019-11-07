#include <iostream>

using namespace std;

int foo(int x, int y)
{
	return x + y;
}

int main()
{
	int x = 1, y = 2;
	foo(6, 7);			// 6,7은 실 매개변수라 한다
	foo(x, y + 1);
	return 0;
}