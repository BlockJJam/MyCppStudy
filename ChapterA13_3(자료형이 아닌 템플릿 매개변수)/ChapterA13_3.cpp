/*
	�ڷ����� �ƴ� ���ø� �Ű�����
*/

#include "MyArray.h"

int main()
{
	int i = 100;
	MyArray<double, 100 > my_arr;	// MyArray<double, i> my_arr; �� �ȵ� (�����Ͻð��� ����������)

	for (int i = 0; i < my_arr.getLength(); i++)
		my_arr[i] = i + 65;

	my_arr.print();

	return 0;
}