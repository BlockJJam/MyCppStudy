/*
	포인터와 const

	const로 선언한 변수를 포인터로 불러올 수는 있다
	de-refer해서 새로 asign은 할 수 없다

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
	ptr = &value3;					//가능 -> ptr이 가리키는 주소를 바꾸는 것은 가능( 위에는 ptr이 가리키는 주소의 값의 변경은 const임)

	int value4 = 5;
	int *const ptr2 = &value4;		// 포인터 상수라고 생각하면됨, ptr2가 가리키는 메모리주소를 바꿀 수 없다

	*ptr2 = 10;						// value4의 값은 바꿀 수 있음
	cout << *ptr2 << endl;
	int value5 = 8; 
	// ptr2 = &value5;(x)			<- 그렇기 때문에 다른 주소를 받아드리지 못함

	const int *const ptr3 = &value5;

	int result_value = 1;
	const int *result_ptr1 = &result_value;
	int *const result_ptr2 = &result_value;
	const int *const result_ptr3 = &result_value;

	return 0;
}