/*
	For-Each
		-> for( : ) 구조
		-> 동적배열에서는 사용 불가능

*/

#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	/*int fibonacci[] = { 0,1,1,2,3,5,8,13,21,34,55,89 };*/
	vector<int> fibonacci = { 0,1,1,2,3,5,8,13,21,34,55,89 };


	// change array values
	for (auto& number : fibonacci)				// 참조변수로 데이터로 받아야 fibonacci 멤버가 바뀜
	{
		//number = 10;
	}


	// output
	for (const auto &number : fibonacci)			// 읽기만 할 것이기 때문에 fibonacci 값을 바꾸지 않겠다
	{
		cout << number << " ";
	}
	cout << endl;

	// max number
	int max_number = numeric_limits<int>::lowest();
	cout << max_number << endl;

	for (const auto& n : fibonacci)
	{
		max_number = max(max_number, n);
	}
	cout << max_number << endl;

	// 동적 배열에서 for-each 불가능 , 단 더좋은거 -> vector ( 맛보기 )

	return 0;
}