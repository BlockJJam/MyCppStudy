/*
	void ������( = ���׸� ������)
	�ڷ����� ������� �����͸� �����Ҽ��� ������? ���� ����

*/

#include <iostream>

using namespace std;

enum Type
{
	INT,
	FLOAT,
	CHAR,
};

int main()
{
	int i = 5;
	float f = 3.0;
	char c = 'a';

	void *ptr = nullptr;

	ptr = &i;
	//ptr = &f;
	//ptr = &c;

	// �Ѱ�� ���� -> �����Ϳ����� �ȵ�
	//cout << ptr + 1 << endl;
	cout << &i << endl;
	cout << ptr << endl;
	cout << *static_cast<int*>(ptr) << endl;

	Type type = FLOAT;		// ���� void �����͸� ����ؾ߸� ���� �� type�� �������ֱ� ���� ����ߴ� ��� -> C++�ֱ� �������� �� ���� ������ ����
	cout << type << endl;
	if (type == FLOAT);		
	else if (type == INT);

	return 0;
}