// 변수가 살아남을 수 있는 범위는 정의한 위치이내 이다. 

#include <iostream>
#include <cmath>

using namespace std;

namespace work1::work11::work111
{
	int a = 3;
	void doSomething()
	{
		a += 3;
	}
}
namespace work2
{
	int a = 4;
	void doSomething()
	{
		a -= 1;
	}
}

int main()
{
	int a = 5;
	cout << a << endl;
	{
		a = 1;
		cout << a << endl;
		int b = 3;
		cout << a << endl;

	}
	//cout << b << endl;  <- 선언한 범위 밖이다
	cout << a << endl;

	a = work2::a;					// ::는 범위결정연산자
	cout << a << endl;
	return 0;
}