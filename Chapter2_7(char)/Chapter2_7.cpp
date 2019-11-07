#include <iostream>

int main()
{
	using namespace std;
	char c1(65);
	char c2('a');
	char c3('c');

	cout << c1 << " " << c2 << " " << int(c1) << " " << int(c2) << endl;

	// c ��Ÿ�� - ����
	cout << (char)65 << endl;
	cout << (int)'A' << endl;


	// C++ ��Ÿ�� -����
	cout << char(65) << endl;
	cout << int('A') << endl;

	// �����Ͽ��� ��ȯ���� ��ȭ�ص� �Ǵ��� ����� ����?
	cout << static_cast<char>(65) << endl;
	cout << static_cast<int>('A') << endl;   // ��ü���⿡���� dynamic_cast�� �ִ�

	cin >> c1;
	cout << c1 << " " << static_cast<int>(c1) << endl;

	cin >> c1;
	cout << c1 << " " << static_cast<int>(c1) << endl;

	cin >> c1;
	cout << c1 << " " << static_cast<int>(c1) << endl;

	cin >> c1;
	cout << c1 << " " << static_cast<int>(c1) << endl;
	// endl ��� flush�� ���ۿ� �ִ°� ��Ƴ���( �ٹٲ� X )

	// �����ڵ�� char_32t ���� �� ū ũ���� char���� ����
	cout << "Hello, \u0444! \n ";

	return 0;
}