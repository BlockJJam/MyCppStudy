#include <iostream>
#include <typeinfo>		// ���� ���ϴ� ������ Ÿ�������� Ȯ�ΰ����� LIB
#include <iomanip>
int main()
{
	using namespace std;

	int a = 123.0;
	cout << typeid(a).name() << endl; // ���ǥ�� : "double'���� 'int'(��)�� ��ȯ�ϸ鼭 �����Ͱ� �սǵ� �� �ֽ��ϴ�"

	double b = 0.123456789;
	float c = b;		// numeric promotion ���� ũ��Ÿ�Կ��� ū ũ�� Ÿ�����δ� ���� ����, �ݴ�δ� ���� ������ �Ѿ�� ĳ���� X

	cout << std::setprecision(12) << c << endl;

	short d = c;
	cout << d << endl;

	int i = 3000;
	char i_char = i;
	cout << static_cast<int>(i_char) << endl;

	//numeric conversion
	cout << static_cast<unsigned int>(5u - 10u); // <- unsigned int�� int���� �켱������ ����
	
	// int, unsigned int, long, unsigned long, long long, unsigned long long ,float, double, long double

	// ����� ��ȯ
	int i = (int)4.0;	// C ��Ÿ��
	int i = int(4.0);	// C++ ��Ÿ��
	int i = static_cast<int>(4.0);	// �ֽ���




	return 0;

}