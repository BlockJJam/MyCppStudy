/*
	���ڿ� �ɺ������( C ��Ÿ�� )
*/

#include <iostream>

using namespace std;

const char* getName()
{
	return "Jackjack";
}

int main()
{
	//char *name = "Jack jack";	-> Error : �������� ���ͷ�, ������ ��� ����� �������� �ʰ�, �����ʹ� �����Ͱ� ����� �޸� �����ּҸ� ����Ų��
	const char *name = getName();			// ��ȣ���� ���ó�� ��밡��
	const char *name2 = getName();
	cout << name << endl;
	cout << (uintptr_t)name << endl;		// name�� name2�� ���� �ּҸ� ���� ����: ���� ���ڿ��̴ϱ� ���� �޸� �����ؼ� ��� 
	cout << (uintptr_t)name << endl;		// name�� name2�� �ٸ� �ּҸ� ���� �Ϸ���? : �ٸ� ���ڿ� �����͸� ������ �ٸ� �޸𸮸� �ο�

	// ���� �������� Ư�� -> cout�� ���������͸� Ư���� �����ش�. ���ڿ��� �����͸� ��½�Ű��, ������ �迭�� �����ּҸ� ���

	char c = 'Q';
	cout << &c << endl;	// ���ڿ��� ���� \0�� ���ö����� �̾Ƴ���



	return 0;
}