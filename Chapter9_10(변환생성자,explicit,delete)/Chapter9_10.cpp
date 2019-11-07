/*
	��ȯ ������, explicit(��ȯ ������ ���ƹ�����), delete(Ư�� �����ڸ� �����ϰ� ���������� ) -> �����Ҵ��� delete�� �ٸ�
*/

#include <iostream>
#include <cassert>
using namespace std;


class Fraction
{
private:
	int _numerator;
	int _denominator;

public:
	Fraction(char) = delete;

	explicit Fraction(int num = 0, int den = 1)
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

void doSomething(Fraction frac)
{
	cout << frac << endl;
}

int main()
{
	Fraction frac(7);

	// doSomething�� Fraction�� ������, 2�� �־��� �� Fraction �⺻�����ڿ� 2�� int num�� �־ ������ -> �ڵ���ȯ������
	//doSomething(2);				// doSomething(Fraction(2));

	// explicit ���� �ڵ���ȯ�����ڸ� ����
	doSomething(Fraction(4));		// doSomething(4) �ȵ�

	// delete Ű���� ����ϱ�
	Fraction frac2('c');			// �������� �ϸ鼭 ���������� ���� �� ���, �ڵ���ȯ������ �����ϰų�

	return 0;
}