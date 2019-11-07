/* 
	동적 할당 배열
	
	! 정적 배열 할당에서는 size를 const로 상수로 박아버렸는데 그 이유는 컴파일 시점에 고정시키기 위해서였다


*/

#include <iostream>

using namespace std;

int main()
{
	int length;

	cin >> length;
	int * array = new int[length] {11,22,33,44,66,55};			// {},()만 넣어줘도 0으로 초기화, 길이보다 더 큰 배열을 선언하면 에러!
	array[0] = 1;
	array[1] = 2;
	for (int i = 0; i < length; i++)
	{
		cout << (uintptr_t)&array[i] << endl;
		cout << array[i] << endl;
	}

	delete []  array;

	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	int fixedArray[] = { 1,2,3,4,5 };

	int *array = new int[5]{ 1,2,3,4,5 };

	delete[] array;

	//resizing이 되는가? 직접적 말고 간접적으로 가능 -> 더 큰 메모리를 가져와서 원래 할당받은 배열을 복사하고 붙이기
	//												 -> OS에게 더큰 메모리 줄 수있나요~ 요청





	return 0;
}