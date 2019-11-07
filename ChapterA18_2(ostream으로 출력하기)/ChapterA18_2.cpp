/*
	ostream���� ����ϱ�
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout.setf(ios::showpos);			// setf() : ��¿ɼ� ����
	cout << 108 << endl;

	cout.unsetf(ios::showpos);			// setf() : ���� ����
	cout << 109 << endl;

	//cout.unsetf(ios::dec);
	cout.setf(ios::hex, ios::basefield);
	cout << 108 << endl;

	//cout.setf(std::ios::uppercase);
	cout << std::hex << std::uppercase;
	cout << 108 << endl;
	cout << 109 << endl;

	cout << std::dec;
	cout << 108 << endl;

	cout << std::boolalpha;
	cout << true << " " << false << endl;

	//cout << std::defaultfloat;
	//cout << std::fixed;									// ���ڰ� �����ڸ��� �Ҽ��� 0���� ����
	//cout << std::scientific;								// �Ҽ����� e+.. �� �����
	cout << std::showpoint;									// .�� ���̰�
	cout << std::setprecision(3) << 123.456 << endl;
	cout << std::setprecision(4) << 123.456 << endl;
	cout << std::setprecision(5) << 123.456 << endl;
	cout << std::setprecision(6) << 123.456 << endl;
	cout << std::setprecision(7) << 123.456 << endl;

	cout << -12345 << endl;
	cout.fill('*');												// ��ĭ�� * �� ä���
	cout << std::setw(10) << -12345 << endl;					// 10ĭ ä��� -12345
	cout << std::setw(10) << std::left << -12345 << endl;		// �������� �ٰ�
	cout << std::setw(10) << std::right << -12345 << endl;		// ���������� �ٰ�
	cout << std::setw(10) << std::internal << -12345 << endl;	// ��ȣ�� ������´�



	return 0;
}