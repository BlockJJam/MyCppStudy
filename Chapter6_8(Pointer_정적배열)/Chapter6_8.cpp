/*
	�����Ϳ� ���� �迭 - ���� ����

	���߿� ���� �迭�� �� �� �߿��� ����
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

void printArray(int *array)				// param => int array[]�� ����, �����͸� �̿�����			
{
	cout << sizeof(array) << endl;
	cout << *array << endl;

	*array = 100;
	cout << array << endl;
}

int main()
{
	int array[5]{ 9,7,5,3,1 };
	cout << array << endl;		// ��� 4����Ʈ �޸� �ּ� -> �� �����ʹ�( �迭�����ּ� )
	cout << *array << endl;

	/*char name[] = "jackjack";
	cout << *name << endl;*/

	int *ptr = array;
	cout << ptr << endl;
	cout << *ptr << endl;
	// -> �����迭�� �����Ͱ� ���̰� ���ٸ� ���Ϸ� ������? -> �������� ���Ǽ������ �� �پ��, �װ� ����� �� �ִ�

	cout << sizeof(ptr) << endl;			// ptr�� �� 4byte�ϱ�? ������ ���� ��ü�� ������

	printArray(array);						// ������ 4�� ����

	cout << array[0] << " " << *array << endl;	// �Լ� �ۿ����� �����ʹ� �ش� �޸��� �ּҸ� �����ϱ� ������ ���� ���� �����ȴ�
												// �̷� ��쿡 C++�� ������ ���

	// ������ ����
	cout << *ptr << " " << *(ptr + 1) << endl;

	// ����ü
	MyStruct ms;
	cout << ms.array[0] << endl;

	doSomething(&ms);							// ms ����ü�� �����ͷ� ������, ����ü�� �Ķ���ͷ� ������ ������� �״�� �����Ǿ� ����

	return 0;
} 