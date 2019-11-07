/*
	�Ϻ��� ������ ���� ����ϴ� std::forward���
*/

#include <iostream>
#include <vector>
#include <utility>	// std::forward

using namespace std;

struct MyStruct
{};

void func(MyStruct& s)
{
	cout << "Pass by L-ref" << endl;
}

void func(MyStruct&& s)
{
	cout << "Pass by R-ref" << endl;
}
//
//void func(MyStruct s)
//{
//	cout << "Pass by Value" << endl;
//}

//template<typename T>		// perfect forwarding �ȵ�!
//void func_wrapper(T t)
//{
//	func(t);
//}

template<typename T>
void func_wrapper(T&& t)
{
	func(std::forward<T>(t));		// ���� t�� L-value�� L-value �Լ��� ������, R-value�� R-value�Լ��� ������
}

int main()
{
	MyStruct s;

	func(s);			// l-value	
	func(MyStruct());	// r-value
	// �� ���� �����Ϸ��� ������ ����, template�� ���� �����Ϸ��� ���� ����

	// perfact forwarding�� ���༭ �ذ�
	func_wrapper(s);
	func_wrapper(MyStruct());



	return 0;
}