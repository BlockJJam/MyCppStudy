/*
	sizeof�� ���� ���� ������ Ÿ���� ũ�⵵ �� �� �ִ�
		���� ���� ()���̵� �� �� �ִ� -> int a; sizeof a;

	,(��ǥ) �����ڴ� ���� ������ �ϰ� �� ������ ������ �޸� ���� ���� ����
		int z  = (++x, ++y); -> ++x; ++y; int z=y;
		,������ �ƴ� �������� ���б�ȣ�θ� ����
	


*/


#include <iostream>
#include <cmath>

using namespace std;

int getPrice(bool onSale)
{
	if (onSale) return 10;
	else return 100;
}
int main()
{

	// conditional operator (arithmetric if)
	bool onSale = true;

	//const int price = (onSale == true) ? 10 : 100;	// <- ������ ���Ǻο��� ���׿����ڰ� ����
	const int price = getPrice(onSale);					// <- �� �� ������ ���Ǻο��� �Լ��� ���°� ����
	
	int x = 5;
	cout << ((x % 2 == 0) ? "even" : "odd") << endl;
	return 0;
}