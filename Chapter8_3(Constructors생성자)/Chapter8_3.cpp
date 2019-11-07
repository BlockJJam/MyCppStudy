#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Fraction						// �м�
{
private : 
	int _numerator;					// ����
	int _denomiator;				// �и�

public:

	// Fraction(){} <- �̰� default�� class�� �����Ǹ� �ڵ����� �����ȴ�, �����ڶ�� �ؼ� value�� ����� ���� ���� �ƴ϶�, class�� ������ �� ȣ��Ǵ� �Լ�
	Fraction(const int& num_in, const int& den_in=1)
	{
		_numerator = num_in;
		_denomiator = den_in;

		cout << "Fraction constructor " << endl;
	}
	void print()
	{
		cout << _numerator << "/" << _denomiator << endl;
	}
};

class Second
{
public:
	Second()
	{
		cout << "class Second constructor() " << endl;
	}
};

class First
{
	Second sec;
public:
	First()
	{
		cout << "class First constructor() " << endl;
	}
};


int main()
{
	//Fraction frac;			// frac() <- X! �Ķ���Ͱ� ���� ��쿡�� �� ������, �Լ��� �ް����� ����
	Fraction one_thirds{ 1,3 };	// = Fraction one_thrids(1,3) , = Fraction one_thirds = Fraction{ 1,3 };
	//Fraction one_thirds( 1,3 ); <- uniformed init�̶��� ������ {}uniformed init�� ĳ���ÿ� ������(�� ���� Ȱ��)
	one_thirds.print();

	//������ ȣ�� ����
	First fir;

	return 0;
}
