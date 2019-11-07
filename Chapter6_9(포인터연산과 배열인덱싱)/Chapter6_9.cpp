/*
	포인터 연산과 배열 인덱식


*/


#include <iostream>

using namespace std;

int main()
{
	//int value = 7;
	//int * ptr = &value;
	//
	//cout << uintptr_t(ptr-1) << endl;		// unsigned int pointer type
	//cout << uintptr_t(ptr) << endl;
	//cout << uintptr_t(ptr+1) << endl;
	//cout << uintptr_t(ptr+2) << endl;

	//int array[] = { 9,7,5,4,1 };
	//int *ptr = array;

	//for (int i = 0; i < 5; i++)
	//{
	//	/*cout << array[i] << " " << (uintptr_t)&array[i] << endl;*/
	//	cout << *(ptr + i) << (uintptr_t)(ptr + i) << endl;
	//}

	char name[] = "Jack jack";
	const int n_name = sizeof(name) / sizeof(char);
	char *ptr = name;
	for (int i = 0; i < n_name; ++i)
	{
		cout << *(name + i);			// name이 배열이고 배열은 포인터로 사용가능
	}
	cout << endl;


	return 0;
}