/*
	Assert - 단언하기
	디버깅에서 활용하는 컴파일 도움을 받을 수 있는
*/

#include <iostream>
#include <cassert> // assert.h
#include <array>
using namespace std;

void printValue(const array<int, 5> &my_array, const int& ix)
{
	assert(ix >= 0);
	assert(ix <= my_array.size() - 1);

	cout << my_array[ix] << endl;
}

int main()
{
	array<int, 5> my_array{ 1,2,3,4,5 };

	printValue(my_array, 100);
	
	//컴파일 타임에 오류를 발생시키는 static_assert
	const int x = 10;
	
	//assert(x==5);
	static_assert(x==5, "x should be 5(as)");



	return 0;
}