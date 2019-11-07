/*
	포인터와 정적 배열 - 둘은 같다

	나중에 동적 배열을 들어갈 때 중요한 개념
*/
#include <iostream>

using namespace std;

struct MyStruct
{
	int array[5]{ 9,7,5,3,1 };
};

void doSomething(MyStruct *ms)
{
	cout << sizeof((*ms).array) << endl;
}

void printArray(int *array)				// param => int array[]와 같다, 포인터를 이용하자			
{
	cout << sizeof(array) << endl;
	cout << *array << endl;

	*array = 100;
	cout << array << endl;
}

int main()
{
	int array[5]{ 9,7,5,3,1 };
	cout << array << endl;		// 결과 4바이트 메모리 주소 -> 즉 포인터다( 배열시작주소 )
	cout << *array << endl;

	/*char name[] = "jackjack";
	cout << *name << endl;*/

	int *ptr = array;
	cout << ptr << endl;
	cout << *ptr << endl;
	// -> 정적배열과 포인터가 차이가 없다면 머하러 나눴나? -> 포인터의 편의성기능이 더 뛰어난데, 그걸 사용할 수 있다

	cout << sizeof(ptr) << endl;			// ptr이 왜 4byte일까? 포인터 변수 자체의 사이즈

	printArray(array);						// 사이즈 4가 나옴

	cout << array[0] << " " << *array << endl;	// 함수 밖에서도 포인터는 해당 메모리의 주소를 참조하기 때문에 변한 값이 유지된다
												// 이런 경우에 C++은 참조를 사용

	// 포인터 연산
	cout << *ptr << " " << *(ptr + 1) << endl;

	// 구조체
	MyStruct ms;
	cout << ms.array[0] << endl;

	doSomething(&ms);							// ms 구조체를 포인터로 보내도, 구조체를 파라미터로 보내면 사이즈는 그대로 유지되어 간다

	return 0;
} 