/*
	Pointer

	���������� !���� �޸𸮸� ���
	���� �Ҵ� �޸𸮴� !�� �޸𸮸� ���

	�޸� �ּҸ� ��� ������ Pointer�� �Ѵ�( ���۷����� �ٸ� ���� )
	
	de-reference operator -> �����Ϳ� �ٸ�����
		==> �����Ͱ� " ���� �ּҿ� ���� �� �����Ͱ� �ִ� "��� �������� ����
		==> de-reference�� " �׷� �ű⿡ ��¥ ������ �ִ��� ���� �鿩�ٺ���"��� �������� ����

	�����͸� �� ����?
		=> �뵵 1) ���� ���, array�� �����غ��� ,�����Ͱ� 100������ ����ְ� array�� parameter�� �ѱ�ٸ�, 100������ �����Ͽ� �Ѿ�� ������ ��������!
		=> �����͸� ���� array�� �޸� ù �ּҸ� �˷��ָ� ��
		=> �뵵 2) ������ �������⼭ ���� �������� �����ؼ� �� �ٿ� ������ ù �ּҸ� ��� �ѱ�� ������ �ʿ䰡 ����

	

*/

#include <iostream>

using namespace std;

struct Something
{
	int a,b,c,d;
};

int main() 
{
	int x = 5;
	double d = 1.0;

	cout << x << endl;
	cout << (&x) << endl;

	//de-reference operator (*)

	cout << *(&x) << endl;

	// -----   pointer   -----
	int *ptr_x ;
	double *ptr_d = &d;				//16������ ���������� ������ �ȵǴµ� ������ ��ȸ�Ͽ� ����� ����
	//typedef int* pint; int�� ������ Ÿ���� ����


	
	
	cout << sizeof(x) << endl;		
	cout << sizeof(&x) << "," << sizeof(ptr_x) << endl;
	cout << sizeof(d) << endl;
	cout << sizeof(&d) << "," << sizeof(ptr_d) << endl;

	Something ss;
	Something *ptr_ss;

	cout << sizeof(Something) << endl;				// 16bytes
	cout << sizeof(ptr_ss) << endl;					// 4bytes

	// C++�� ������ ������ ���� �Ͼ�°� �η��� ��
	cout << ptr_x << endl;							// ������ ���� ���ְ�(ptr_x��) �� ���α׷��� ������� �ʴ� �޸��ּҸ� ������ �� ���� �ִ°�




	return 0;
}