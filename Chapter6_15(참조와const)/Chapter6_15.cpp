/*
	참조와 const
	함수의 파라미터로 참조를 사용할 때 좋다

	참조 매개변수에 const를 붙이면 literal(숫자,string.. 값들)을 바로 붙일 수 있다

*/
#include <iostream>

using namespace std;

void doSomething(const int& x)			// const 참조 매개변수를 넣으면 리터럴도 매개변수로 넣을 수 있다 -> 24번째줄부터
{
	cout << x << endl;
}

int main()
{
	const int x = 5;
	const int &ref_x = x;
	const int &ref_liter = 1 + 2;		// 참조에서 const선언하면 피연산자에 리터럴 사용가능

	const int &ref_2 = ref_x;

	doSomething(ref_liter);
	doSomething(1);						// 참조매개변수에 리터럴 사용가능
	doSomething(ref_liter + 3);
	doSomething(3 * 4);



	return 0;

}