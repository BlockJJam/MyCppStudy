/*
< Ű����(�����)�� �ĺ��� �̸����� >

override, final <- C+11����
transaction_safe, transaction_safe_dynamic <- TM TS

�� �˰� �ֵ��� �Լ����� ������, �������� �����
�տ� _apples ���� ���ξ� _�� ����ϴ� ����
  1. OS�� �ý��� ���α׷����� ����� ��
  2. ��ü������ Ŭ������ ����� ������ ��( ���� ���� ������ ����η� �ٷΰ��� �����ϱ�)

*/
#include <iostream>
using namespace std;

int addNumber() //...........
{
	return;
}

int main()
{
	addNumber();

	return;
}