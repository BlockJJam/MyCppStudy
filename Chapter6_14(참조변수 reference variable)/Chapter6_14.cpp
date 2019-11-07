/*
	���� ����

	1) ������ �������� ���� �� �ִ�
	2) ������ �־�� �ϴϱ� �ʱ�ȭ �ʼ�
	3) �ǿ����ڷ� ������ ���� �Ѵ�

	���� �߼��� �Ű����� ���� ���ٲٰ� �ϴ� ���� �߼� -> �Ű������� const��
	�Է��� �����ϰ� �Է¸�(��������), ��ȯ�� �������� �޾Ƶ� �ȴ�
*/

#include <iostream>

using namespace std;

void doSomething(const int &n)
{
	//n = 10;
	cout << &n << endl;							// �����ͷ� �Ű������� �ѱ�� �ּҰ� �ٸ��� ����(����), ���������� �Ű������� �ѱ�� ������ü �޸𸮰� �Ѿ(����(ȿ��))
	cout << " In doSomething " << n << endl;		
}

void printElements(int(&arr)[5])
{
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st;
};


int main()
{
	int value = 5;
	
	//������
	int *ptr = nullptr;
	ptr = &value;

	//����
	int &ref = value;		// value�� ���� �޸𸮸� ����
	
	cout << ref << endl;

	ref = 10;	// *ptr =10;

	cout << value << " " << ref << endl;

	cout << &value << endl;
	cout << &ref << endl;
	cout << ptr << endl;
	cout << &ptr << endl;

	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	int x = 5;
	int &ref_x = x;
	const int y = 8;	
	const int &ref_y = y;		// const�� �����Ҷ��� reference�� const��

	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	// reasign

	int value1 = 5;
	int value2 = 10;
	int &ref3 = value1;

	cout << ref3 << endl;
	ref3 = value2;
	cout << ref3 << endl;
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	// �Ű������� ���������� �Ѱ��ٶ�

	int n = 5;
	cout << n << endl;
	cout << &n << endl;

	doSomething(n);

	cout << n << endl;

	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	
	// arr�� ���������� �Ű������� �ѱ涧
	const int length = 5;
	int arr[length] = { 1,2,3,4,5 };

	printElements(arr);

	// ����ü
	Other ot;
	ot.st.v1 = 1.0;		// ���� ����

	int  &v1 = ot.st.v1;	// ���� ���� ���
	v1 = 1;

	// ���������� ������ ��
	int value3 = 5;
	int value4 = 6;
	int *const ptr2 = &value3;	// �ּ� ���ٲ�
	int &ref4 = value3;

	// ptr2 = &value4;
	ref4 = value4;
	cout << "ref4 :" << &ref4 << endl;
	cout << "value3 : " << &value3 << endl;
	return 0;
}