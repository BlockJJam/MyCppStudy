#include <iostream>
#include "MY_CONSTANTS.h"
#define PRICE_PER_ITEM 30

using namespace std;

void printNumber(const int my_number)	// �Ķ���Ϳ� ���� �Ű������� �Լ� �ȿ��� �ٲٴ� ���� �幰��
{
	int n = my_number;
	cout << n << endl;
}

int main()
{
	/*const double gravity{ 9.8 }; 
	printNumber(123);*/

	const int my_const(123);					// ������ Ÿ�� ���
	constexpr int my_const2(123);				// ��������� ������Ÿ�ӿ� ����� �����ϰڴ�
	int number;
	cin >> number;
	const int special_number(number);			// ��Ÿ�� ���

	int num_item = 123;
	int price = num_item * PRICE_PER_ITEM;		// ��ũ�δ� �� �Ⱦ��� 1. ������� ���� 2. ��������� �ʹ� ũ��

	const int price_per_item = 30;

	double radius = 1.3;
	double circumference = 2.0 * radius * constants::pi; // ����� ����Ϸ��� ������Ϸ� ���� ����ص� ����


	return 0;
}