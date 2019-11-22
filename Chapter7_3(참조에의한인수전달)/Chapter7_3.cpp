#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void addOne(int &y)
{
	y = y + 1;
	cout << y << " " << &y << endl;
}

void getSinCos(const double &degrees, double&sin_out, double &cos_out)		// const �Է�, ����&�� ���
{
	static const double pi = 3.141592 / 180.0;	// �Լ� ���� ������ �޸𸮸� ��°� �ƴ� �ѹ� ��� �� �̿�
	double radians = degrees * pi;
	sin_out = sin(radians);
	cos_out = cos(radians);
}

void foo(const int &x)				// Modern C++ �Է����ڴ� ���� X�ǰ�(Const int &) ��ȯ�� �������� �����°� ��������
{
	cout << x << endl;
}


// void foo2(int* &ptr)
typedef int* pint;
void foo2(pint ptr)
{
	cout << ptr << " " << &ptr << endl;
}

// array param
//void printElements(int(&arr)[4])
void printElements(vector<int> &arr)
{

}

int main()
{
	int x = 6;
	cout << x << " " << &x << endl;

	addOne(x);

	cout << x << " " << &x << endl;

	double sin(0.0);
	double cos(0.0);
	
	getSinCos(30.0 ,sin, cos);

	cout << sin << " " << cos << endl;

	//�����Ű������� �����ڸ� ������ �ּҰ� �����Ƿ� ����, const�� �Լ� �Ű������� �ٲ��ָ� ����
	foo(6);

	//�����Ϳ� ���� ���۷����� �Ű������ε� ����

	x = 5;
	pint ptr = &x;
	cout << ptr << " " << &ptr << endl;

	foo2(ptr);

	// array�� parameter�� �����ϴ� ���
	//int arr[]{ 1,2,3,4 };
	vector<int> arr{ 1,2,3,4 };
	printElements(arr);

	return 0;
}