/*
	������ const
	�Լ��� �Ķ���ͷ� ������ ����� �� ����

	���� �Ű������� const�� ���̸� literal(����,string.. ����)�� �ٷ� ���� �� �ִ�

*/
#include <iostream>

using namespace std;

void doSomething(const int& x)			// const ���� �Ű������� ������ ���ͷ��� �Ű������� ���� �� �ִ� -> 24��°�ٺ���
{
	cout << x << endl;
}

int main()
{
	const int x = 5;
	const int &ref_x = x;
	const int &ref_liter = 1 + 2;		// �������� const�����ϸ� �ǿ����ڿ� ���ͷ� ��밡��

	const int &ref_2 = ref_x;

	doSomething(ref_liter);
	doSomething(1);						// �����Ű������� ���ͷ� ��밡��
	doSomething(ref_liter + 3);
	doSomething(3 * 4);



	return 0;

}