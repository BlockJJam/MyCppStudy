/*
	생략부호 
*/
#include <iostream>
#include <string>
#include <cstdarg> // for 생략부호ellipsis
using namespace std;

double findAverage(int count, ...)					// count - 파라미터개수
{
	double sum = 0;

	va_list list;									// 문자열로 받음

	va_start(list, count);							// 몇개가 들어갈건지	

	for (int arg = 0; arg < count; ++arg)
		sum += va_arg(list, int);					// int로 캐스팅해서 list에 들어감

	va_end(list);

	return sum / count;
}

int main()
{
	cout << findAverage(1, 1, 2, 3, "Hello", 'c') << endl;	// 첫번째 1이 카운트
	cout << findAverage(3, 1, 2, 3) << endl;
	cout << findAverage(5, 1, 2, 3, 4, 5) << endl;
	cout << findAverage(10, 1, 2, 3) << endl;				// 카운트 개수를 넘으면 안돼

	return 0;
}