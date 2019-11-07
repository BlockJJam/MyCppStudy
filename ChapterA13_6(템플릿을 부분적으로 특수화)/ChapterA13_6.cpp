/*
	���ø��� �κ������� Ư��ȭ
		-> Ŭ���� ��� �Լ��� specialization�ϴ� ���� �ٷ� ������ �ϴ� ���� �ƴ϶�
		-> Ŭ���� ����� �޾Ƽ� �ۼ��ؾ� ���� �κ�ȭ �� �� �ִ�
*/

#include <iostream>
#include <string>

using namespace std;

template< class T, int size>
class StaticArray_BASE
{
private:
	T _array[size];

public:
	T * getArray()
	{
		return _array;
	}

	T& operator [] (int index)
	{
		return _array[index];
	}
	void print()
	{
		for (int count = 0; count < size; count++)
			cout << (*this)[count] << ' ';
		cout << endl;
	}
};

template< class T, int size>
class StaticArray : public StaticArray_BASE<T, size>
{

};

template< int size>
class StaticArray<char, size> : public StaticArray_BASE<char, size>
{
public:
	void print()
	{
		for (int count = 0; count < size; count++)
			cout << (*this)[count];
		cout << endl;
	}
};

//template <int size>
//void print(StaticArray<char, size> &array)
//{
//	for (int count = 0; count < size; count++)
//		cout << array[count];
//	cout << endl;
//}

int main()
{
	StaticArray<int, 4> int4;

	for (int i = 0; i < 4; i++)
		int4[i] = i;

	int4.print();

	StaticArray<char, 14> char14;
	char14[0] = 'H';
	char14[1] = 'E';

	strcpy_s(char14.getArray(), 14, "Hello, World");

	char14.print();

	return 0;
}