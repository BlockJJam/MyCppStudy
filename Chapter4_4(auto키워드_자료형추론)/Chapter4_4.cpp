
#include <iostream>
#include <cmath>

using namespace std;

auto add(int x, int y) -> int			// �Ű������δ� auto�� ���� �������� (template�� ���� ���ϴ� �ڿ� ��)
{										// "-> int" �� Ʈ���ϸ����� return Ÿ������ ��������
	return x + (double)y;
}
int main()
{
	auto a = 123;
	auto b = 123.0;
	auto c = 1 + 2.0;
	auto d = 'A';
	auto e = "hello";

	auto result = add(1 ,2);

	cout << a << " " << b << " " << c << " " << d << " " << e << " " << endl;
	cout << result << endl;
	return 0;
}