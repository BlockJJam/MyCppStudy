#include <iostream>
#include <array>
#include <tuple>
using namespace std;

int getValue(int x)
{
	int value = x * 2;
	return value;
}

int* getValue2(int x)
{
	int value = x * 2;
	return &value;
}

int* allocateMemory(int size)
{
	return new int[size];
}

int& getValue3(int x)
{
	int value = x * 2;
	return value;
}

int& getElement(array<int, 100>& my_array, int ix)
{
	return my_array[ix];
}

struct S
{
	int a, b, c, d;
};

S getStruct()
{
	S my_s{ 1,2,3,4 };
	return my_s;
}

tuple<int, double,double> getTuple()
{
	int a = 10;
	double d = 3.14;
	double b = 3.3;
	return make_tuple(a, d, b);
}

int main()
{
	int value = getValue(3);

	//�ּҰ����� �����ޱ�
	int value2 = *getValue2(3);				//����� ������ ���� de-ref�Ѵٴ°� ������ ���߰��ɼ� ���� *value = getValue(3); �� �� ����

	cout << value2 << endl;

	//�����迭 �Ҵ� new�� ���� ����ϰ� ���� ��
	int *my_array = allocateMemory(1024);
	
	delete[] my_array;

	// �������� ��ȯ
	int &value3 = getValue3(5);

	cout << value3 << endl;
	cout << value3 << endl;					// ���������� ���ǰ� ������� ������ �����Ⱚ�� ��

	array<int, 100> my_arr;
	my_arr[30] = 10;

	getElement(my_arr, 30) *= 10;
	cout << my_arr[30] << endl;

	// ������ ����
	S my_s = getStruct();
	my_s.b;										// 1) ����ü ->�̷��� ���� ��������

	tuple<int, double,double> my_tp = getTuple();		// 2) Ʃ�� -> ������ ���� ����
	cout << get<0>(my_tp) << " ";
	cout << get<1>(my_tp) << endl;

	auto[a, b,c] = getTuple();					// 3) C++17��Ÿ��
	cout << a << endl;
	cout << b << endl;

	return 0;
}