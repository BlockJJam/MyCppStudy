// chapter1_14.cpp : Defines the entry point for the console 

#include <iostream>
#include <algorithm>

using namespace std;

#define MY_NUMBER 333				// 매크로 : 교체기
#define MAX(a,b) (((a)>(b)) ? (a) :(b))
#define LIKE_APPLE				// define의 범위 : 파일 안에서

void doSomething();

int main()
{
	cout << MY_NUMBER << endl;
	cout << MAX(1+3, 2) << endl; // 굳이 누가 이렇게 안한다
	cout << max(4, 2) << endl;

	doSomething();
	return 0;
}