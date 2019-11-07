/*
	C++17에서의 여러 개의 리턴값 반환하기
*/

#include <iostream>
#include <tuple>		// 조금 예전

using namespace std;

//tuple<int, int> my_func()				// 1)
//{
//	return tuple<int, int>(123, 456);
//}

//auto my_func()							// 2)
//{
//	return tuple<int, int, int>(123, 456, 789);
//}

auto my_func()							// 3) 최신
{
	return tuple(123, 456, 789,1000);
}

int main()
{
	/*tuple<int, int> result = my_func();

	cout << get<0>(result) << get<1>(result) << endl;*/
	auto[a, b, c, d] = my_func();

	cout << a << " " << b << " " << c << " " << d << endl;
	return 0;
}