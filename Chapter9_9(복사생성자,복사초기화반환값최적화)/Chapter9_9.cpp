/*
	���������, �����ʱ�ȭ, ��ȯ�� ����ȭ
*/

#include <iostream>
#include <cassert>
using namespace std;

// �м�
class Fraction
{
private:
	int _numerator;
	int _denominator;
public:
	Fraction(int num = 0, int den = 1)
		: _numerator(num), _denominator(den)
	{
		assert(den != 0);
	}

	Fraction(const Fraction &fraction)												// Copy constructor
		: _numerator(fraction._numerator), _denominator(fraction._denominator)
	{
		cout << "Copy constructor called" << endl;
	} 

	friend std::ostream & operator << (std::ostream & out, const Fraction & f)
	{
		cout << f._numerator << " / " << f._denominator << endl;
		return out;
	}
};

Fraction doSomething()
{
	Fraction temp(1, 2);
	cout << &temp << endl;

	return temp;
}

int main()
{
	Fraction frac(3, 5);

	//copy initialization
	//Fraction fr_copy= frac;
	Fraction fr_copy = Fraction(3, 10);			// ���� �����ڰ� ���� X, �����Ϸ��� �˾Ƽ� Fraction fr_copy(3,10)���� �Ϲ� �����ڷ� ������

	cout << frac << " " << fr_copy << endl;

	// � �Լ��� Fraction�� �������� ��
	Fraction result = doSomething();
	
	cout << result << endl;						// debug��忡�� doSomething()���� �⺻�����ϰ�, result���� copy construct ���ִµ� ����
	cout << &result << endl;					// release ��忡�� �Ϲ� �����ڷ� �����Ѵ� -> ��ȯ�� �ʱ�ȭ

	return 0;
}