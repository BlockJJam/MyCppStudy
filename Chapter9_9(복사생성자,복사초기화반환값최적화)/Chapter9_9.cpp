/*
	복사생성자, 복사초기화, 반환값 최적화
*/

#include <iostream>
#include <cassert>
using namespace std;

// 분수
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
	Fraction fr_copy = Fraction(3, 10);			// 복사 생성자가 생성 X, 컴파일러가 알아서 Fraction fr_copy(3,10)으로 일반 생성자로 생성함

	cout << frac << " " << fr_copy << endl;

	// 어떤 함수가 Fraction을 리턴해줄 때
	Fraction result = doSomething();
	
	cout << result << endl;						// debug모드에선 doSomething()에서 기본생성하고, result에서 copy construct 해주는데 반해
	cout << &result << endl;					// release 모드에선 일반 생성자로 생략한다 -> 반환값 초기화

	return 0;
}