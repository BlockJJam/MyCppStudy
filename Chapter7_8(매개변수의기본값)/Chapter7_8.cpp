/*
	�Ű������� �⺻��


*/

#include <iostream>
#include <string>

using namespace std;

/*
// ���� error!! ���ǳ� ���� �� �� �ϳ����� �Ű����� �⺻���� ����, header������ ���� �⺻���� ǥ�������� ���
void print(int x = 10, int y = 20, int z = 0); // in header
void print(int x,int y, int z)		// �⺻���� ��� �ְų� ���� �� �ְ�, 1���� 2���� ���� �� ������, ������ �Ű��������� ä������ �Ѵ�
{
	cout << x << endl;
}
*/
// �Լ� �����ε��� �Բ� �϶��� ��ȣ������ ���� Error
// ����
void print(string str) {}
void print(char ch = ' '){}
// �Ұ���
void print_int(int x) {}
void print_int(int x, int y = 10) {}


int main()
{
	print();		// �ι� ° print�� ��
	print_int(10);	// ���� ����
	return 0;
}