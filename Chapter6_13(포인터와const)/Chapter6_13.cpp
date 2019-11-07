/*
	�����Ϳ� const

	const�� ������ ������ �����ͷ� �ҷ��� ���� �ִ�
	de-refer�ؼ� ���� asign�� �� �� ����

*/

#include <iostream>

using namespace std;

int main()
{
	const int value = 5;
	const int *ptr = &value;
	//  *ptr = 6; (x)

	int value2 = 5;
	const int *ptr = &value;
	//  *ptr = 6; (x)
	value2 = 6;
	
	int value3 = 6;
	ptr = &value3;					//���� -> ptr�� ����Ű�� �ּҸ� �ٲٴ� ���� ����( ������ ptr�� ����Ű�� �ּ��� ���� ������ const��)

	int value4 = 5;
	int *const ptr2 = &value4;		// ������ ������ �����ϸ��, ptr2�� ����Ű�� �޸��ּҸ� �ٲ� �� ����

	*ptr2 = 10;						// value4�� ���� �ٲ� �� ����
	cout << *ptr2 << endl;
	int value5 = 8; 
	// ptr2 = &value5;(x)			<- �׷��� ������ �ٸ� �ּҸ� �޾Ƶ帮�� ����

	const int *const ptr3 = &value5;

	int result_value = 1;
	const int *result_ptr1 = &result_value;
	int *const result_ptr2 = &result_value;
	const int *const result_ptr3 = &result_value;

	return 0;
}