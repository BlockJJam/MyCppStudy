/*
	오른쪽 값 참조
		-> move semantics 를 사용해도 되는 지 판단하기 위해
		-> L-value : 다른 어디선가 사용하려고 접근 할 수 있도록 애들 ( int x )
		-> R-value : 임시로 사용하려는 값들	( 5 )
		-> ( const int &&rr1 = 5; ) => R-value reference : &&rr , R-value : 5

		즉, 오른쪽 값 참조는 나의 r-value는 나만이 rr1에 접근할 수 있고, 값을 바꿀 수 있어라는 의미
*/

#include <iostream>
using namespace std;

void doSomething(int &lref)
{
	cout << "L-value ref" << endl;
}

// L value와 R value는 오버로딩 가능
void doSomething(int &&ref)				// 메모리에 잠깐 저장되고 말 애들을 R-value ref가 받아서 처리가능하다 
{
	cout << "R-value ref" << endl;
}

int getResult()
{
	return 5;
}


int main()
{
	int x = 5;
	int y = getResult();
	const int cx = 6;
	const int cy = getResult();

	// L-value reference

	int &lr1 = x;			// Modifiable l-values
	//int &lr2 = cx;		// Non-modifiable l-values
	//int &lr3 = 5;			// R-values	<- 중요

	const int &lr4 = x;		// Modifiable l-values
	const int &lr5 = cx;	// Non-modifiable l-values
	const int &lr6 = 5;		// R-values	<- 중요

	// R - value reference

	//int &&rr1 = x;
	//int &&rr2 = cx;
	int &&rr3 = 5;				// R-value 만 가질 수 있음 -> 임시저장될 애를 메모리에 저장 
	int &&rr7 = getResult();	// 곧 사라질 애들만 가질 수 있음

	cout << rr3 << endl;
	rr3 = 10;
	cout << rr3 << endl;

	// const int &&rr4 =x;
	// const int &&rr5 = cx;
	const int &&rr6 = 5;

	doSomething(x);
	doSomething(5);
	doSomething(getResult());

	return 0;
}