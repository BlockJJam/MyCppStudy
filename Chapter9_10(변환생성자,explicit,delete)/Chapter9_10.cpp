/*
	변환 생성자, explicit(변환 생성자 막아버리기), delete(특정 생성자를 사용못하게 지워버리는 ) -> 동적할당의 delete와 다름
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

	// doSomething이 Fraction을 받지만, 2를 넣었을 때 Fraction 기본생성자에 2를 int num에 넣어서 생각함 -> 자동변환생성자
	//doSomething(2);				// doSomething(Fraction(2));

	// explicit 으로 자동변환생성자를 막기
	doSomething(Fraction(4));		// doSomething(4) 안됨

	// delete 키워드 사용하기
	Fraction frac2('c');			// 버전업을 하면서 예전버전을 막을 때 사용, 자동변환생성을 걱정하거나

	return 0;
}