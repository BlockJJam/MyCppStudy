/*
	������ ����� �迭 �ε���


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
		cout << *(name + i);			// name�� �迭�̰� �迭�� �����ͷ� ��밡��
	}
	cout << endl;


	return 0;
}