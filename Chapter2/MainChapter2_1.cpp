//void : ������ ���� �ʴ� ��Ʈ�� Ÿ��

#include <iostream>

int main()
{
	using namespace std;

	bool bValue = true;
	char chValue = 65;
	float fValue = 3.141592f;
	double dValue = 3.141592;

	// auto Ÿ�� : int,char,double �� float ���̰� �ָ��� �� modern C++���� ���� ���ο� �ε��Ҽ��� Ÿ��
	auto aValue = 3.141592;
	auto aValue2 = 3.141592f;
	auto aValue3 = 'A';
	cout << fValue << endl;
	cout << sizeof(aValue) << endl;
	cout << sizeof(aValue2) << endl;
	cout << aValue3 << endl;

	//���� �ʱ�ȭ 3���� ���
	int i = 0;			// copy initialization
	int a(0);			// direct initialization
						//int a(3.14); <- ��� 
	int b{ 123 };		// uniform initialization  ��ü���⿡�� �߿�
						//int b{ 4.5 }; <- ���� , uniform �� ���� ����
						// ��, copy�� direct �ʱ�ȭ�� �ε��Ҽ����� �־ �������� ����, uniform�� �Ұ���

	int k, 1, m = 123;	// ������ �ѵ� �ʱ�ȭ ��Ÿ���� ������� ���� �ʱ�ȭ���ְ�, ���� �����ִ� ���� X


	return 0;

}