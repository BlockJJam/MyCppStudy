// ������ ��Ƴ��� �� �ִ� ������ ������ ��ġ�̳� �̴�. 

#include <iostream>
#include <cmath>

using namespace std;

namespace work1::work11::work111
{
	int a = 3;
	void doSomething()
	{
		a += 3;
	}
}
namespace work2
{
	int a = 4;
	void doSomething()
	{
		a -= 1;
	}
}

int main()
{
	int a = 5;
	cout << a << endl;
	{
		a = 1;
		cout << a << endl;
		int b = 3;
		cout << a << endl;

	}
	//cout << b << endl;  <- ������ ���� ���̴�
	cout << a << endl;

	a = work2::a;					// ::�� ��������������
	cout << a << endl;
	return 0;
}