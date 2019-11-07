#include <iostream>
#include <cmath>
#include <bitset> // ��Ʈ�� ��� ���̴��� Ȯ���� �� �ִ� ���̺귯��

using namespace std;

int main()
{
	unsigned int a = 3;

	cout << std::bitset<8>(a) << endl;

	unsigned int b = a << 3;

	cout << bitset<8>(b) << " " << b << endl;

	a = 1024;

	cout << bitset<16>(a >> 1) << " " << (a >> 1) << endl;

	cout << bitset<16>(~a) << " " << (~a) << endl;

	a = 0b0110;
	cout << bitset<16>(a >> 2) << endl;

	return 0;
}