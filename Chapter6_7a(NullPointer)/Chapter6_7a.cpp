/*
	Null Pointer
	 => �������ּҿ� �����Ⱚ�� �� ������ de-ref�� �� ������ ���� ���� ������ �� �ֱ� ������ OS�� ��� ��
	 => ���� ������ �����ϱ� ���� ����ϴ�  NULL Pointer���

*/
#include <iostream>
#include <cstddef>


using namespace std;

void doSomething(double *ptr)
{
	cout << "address of pointer variable in main() " << &ptr << endl;
	if (ptr != nullptr)
	{
		cout << *ptr << endl;
	}
	else
	{
		cout << "Null ptr, do nothing " << endl;
	}
}
int main()
{
	// null pointer - modern C++
	double *ptr_d = nullptr;
	
	doSomething(ptr_d);
	doSomething(nullptr);

	double d = 123.4;
	ptr_d = &d;
	doSomething(&d);
	doSomething(ptr_d);
	
	nullptr_t nptr;		// �Ķ���Ϳ� nullptrŸ�Ը� ���� �� ����Ѵ�
	
	// ������ ������ �ּҴ�?
	cout << "address of pointer variable in main() " << &ptr_d << endl;			// ��, �Ķ���ʹ� ���������̹Ƿ�, �����ͺ��� �ּҿ� �Ķ���� ������ ���� �ּҴ� ���� �ٸ���
	doSomething(ptr_d);

	return 0;
}