/*
	inline 함수
		-> 해당 함수를 자주 찾으면서 구현 오버헤드를 줄이기 위해 사용
		-> 함수가 호출되는 개념이 아닌 컴파일 시점에 해당 함수 내용을 호출한 부분에 갖다놓음 -> 호출하는 과정이 없어짐
		-> 컴파일에 강제가 아니라 , 컴파일러가 판단하에 inline을 받아들인다
		-> 또한 컴파일러 발달로 inline함수를 설정안해도 알아서 inline을 활용한다
*/

#include <iostream>

using namespace std;

inline int min(int x, int y)
{
	return (x < y) ? x : y;
}

int main()
{
	cout << min(1, 2) << endl;
	return 0;
}
