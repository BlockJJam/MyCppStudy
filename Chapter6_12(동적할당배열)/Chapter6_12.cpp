/* 
	���� �Ҵ� �迭
	
	! ���� �迭 �Ҵ翡���� size�� const�� ����� �ھƹ��ȴµ� �� ������ ������ ������ ������Ű�� ���ؼ�����


*/

#include <iostream>

using namespace std;

int main()
{
	int length;

	cin >> length;
	int * array = new int[length] {11,22,33,44,66,55};			// {},()�� �־��൵ 0���� �ʱ�ȭ, ���̺��� �� ū �迭�� �����ϸ� ����!
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

	//resizing�� �Ǵ°�? ������ ���� ���������� ���� -> �� ū �޸𸮸� �����ͼ� ���� �Ҵ���� �迭�� �����ϰ� ���̱�
	//												 -> OS���� ��ū �޸� �� ���ֳ���~ ��û





	return 0;
}