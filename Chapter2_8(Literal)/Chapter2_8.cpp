#include <iostream>

int main()
{
	using namespace std;

	float pi = 3.14f;			// �ڿ� f�� ������ double�� �Ǵ�
	int i = -1234u;				// �ڿ� u�� ������ unsigned�� �Ǵ�
	int l = 12324LL;			// ĳ������ �� ��Ȯ�� �� �� �ִ�

	cout << pi << " " << i << " " << l << endl;

	int x = 0b10;				// ��η� 0�� 8���� 0x�� 16���� 0b�� ������

	// ���������� '�� �����Ϸ��� �Ű�Ⱦ�
	x = 0b1000'1111'1000'0101;
	cout << x << endl;
	
	// ���ͷ� ����� �ڵ忡 �ְ� ������ �ǹ̸� ���� �̸����� �������´�
	const int price_per_item = 10;
	int num_items = 123;
	int price = num_items * price_per_item;
	cout << "price:  " <<price << endl;

	return 0;
}