/*
	static�� �ٸ� cpp���Ͽ��� ������ �� ����
	���������� �ٸ� ���Ͽ����� ������ �� �ִ�

	int g_x;				// external linkage
	static int g_x;			// internal linkage	- �ٸ� cpp���Ͽ��� ���� �Ұ�
	const int g_x;			// X

	extern int g_z;			
	extern const int g_z ;	// �ٸ������� �ʱ�ȭ ���־ ���漱�� ����

	int g_y(1);					// external linkage
	static int g_y(1);			// internal
	const int g_y(1);			// external

	extern int g_w(1);			// external
	extern const int g_w(1);	// exteranl
*/

#include <iostream>
#include "MyHeader.h"

using namespace std;
//int value = 1;
//static int g_a = 1;

//forward declaration
extern void doSomething();		// ��򰡿� extern(�ܺ�)�� doSomething()�� ������ ���漱���ߴ�
extern int a;				// a�� test.cpp���� ����Ǿ� �ְ�, ���������ε� ����Ǿ��ִ�
/*
void doSomething()
{
	static int a = 1;			// static�� �̿��ϸ� �޸� ���� , a�� ���� �޸𸮰� static�̴� , 
								// OS�� �޸��ּҸ� static���� �ѹ��� �Ҵ�(������ �ʱ�ȭ �ʿ�)�ϰ� �ٽ� ȣ������ �� static��
								// �̹� �ּҸ� �Ҵ��߱� ������ �ٽ� �ʱ�ȭ���� �ʴ´� ��, �޸� ȸ���� �ٷ� ���� �ʴ´�
								// ������������ ������ : ���������� ������ ���� ��������� �ʹ� ����( ��� : ��η�g_, �Ű�����)
								//						��, static�� hide�ؼ� ���������� ������ ��ƴ�
	++a;
	cout << a << endl;
}
*/

int main()
{
	int value = 2;

	//���������� ::�̿�
	//cout << ::value << endl;
	//�������� ȣ��
	//cout << value << endl;
	cout << a << endl;

	cout << "In main.cpp " << Constants::pi << " " << &Constants::pi<< endl;	// ��� ���Ͽ� �۷ι������� �Լ��� ����ϸ�
																				// test.cpp�� �ּҿ� �ٸ��� -> �޸� ����
																				// MyConstant.cpp�� ���� ���� ������ �ؼ�
																				// ������ �� ��쿡 �޸𸮸� �������� ����
	doSomething();

	return 0;
}

