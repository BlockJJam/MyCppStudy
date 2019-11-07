/*
	������ȣ 
*/
#include <iostream>
#include <string>
#include <cstdarg> // for ������ȣellipsis
using namespace std;

double findAverage(int count, ...)					// count - �Ķ���Ͱ���
{
	double sum = 0;

	va_list list;									// ���ڿ��� ����

	va_start(list, count);							// ��� ������	

	for (int arg = 0; arg < count; ++arg)
		sum += va_arg(list, int);					// int�� ĳ�����ؼ� list�� ��

	va_end(list);

	return sum / count;
}

int main()
{
	cout << findAverage(1, 1, 2, 3, "Hello", 'c') << endl;	// ù��° 1�� ī��Ʈ
	cout << findAverage(3, 1, 2, 3) << endl;
	cout << findAverage(5, 1, 2, 3, 4, 5) << endl;
	cout << findAverage(10, 1, 2, 3) << endl;				// ī��Ʈ ������ ������ �ȵ�

	return 0;
}