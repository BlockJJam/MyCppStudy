/*
	���� �޸��Ҵ�

	1) static  : ����,���� �޸� �Ҵ�  
	2) �ڵ� �޸��Ҵ� : �� �ȿ����� �޸� �Ҵ�
	3) ���� �޸��Ҵ� : �ʿ�� ���� �ð� ���ȿ��� ����ϴ� �޸� �Ҵ�
*/

#include <iostream>

using namespace std;

int main()
{
	int array[10000];		// stack ��������� ���� ũ�� <-> ����(��)�޸� ��������� ū ũŰ
	new int;				// int ������ os���� �ް� 

	int *ptr = new (std::nothrow) int{ 7 };		// ==int var; var= 7; 
									// std::nothrow�� �޸� ������ �߻��Ѵٸ� ����ó���� ���� �ʰ� �޸� Ȯ���� �Ҥ���

	cout << ptr << endl;
	cout << *ptr << endl;

	delete ptr;						// �̰� ������ ���α׷� ����ÿ� OS�� �Ⱦ
	ptr = nullptr;					// delete �޸� �ݳ��� 1) ���α׷��Ӱ� �Ű�Ἥ �� �ݳ� 2) ����Ʈ �����Ϳ��� ��� ���

	cout << "After delete" << endl;
	if (ptr != nullptr)
	{
		cout << ptr << endl;
		cout << *ptr << endl;			// �޸� ��ȯ�Ǽ� ������ ���� ���
	}
	else
	{
		cout << "Could not allocate memory" << endl;
	}

	// memory leak
	while (true)
	{
		int *ptr = new int;				// ���� �ȵǴ� ���� : �̷� �ڵ��� ���� ���� ����
		cout << ptr << endl;

		delete ptr;						// new - delete ������ ���� -> OS ���ļ� �;���				
	}



	return 0;
}