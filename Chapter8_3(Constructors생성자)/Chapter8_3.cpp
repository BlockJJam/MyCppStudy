#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Fraction						// 분수
{
private : 
	int _numerator;					// 분자
	int _denomiator;				// 분모

public:

	// Fraction(){} <- 이게 default로 class가 생성되면 자동으로 생성된다, 생성자라고 해서 value를 만들어 내는 것이 아니라, class가 생성될 때 호출되는 함수
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
	//Fraction frac;			// frac() <- X! 파라미터가 없을 경우에만 꼭 빼놓자, 함수랑 햇갈리기 때문
	Fraction one_thirds{ 1,3 };	// = Fraction one_thrids(1,3) , = Fraction one_thirds = Fraction{ 1,3 };
	//Fraction one_thirds( 1,3 ); <- uniformed init이랑의 차이점 {}uniformed init은 캐스팅에 엄격함(더 많이 활용)
	one_thirds.print();

	//생성자 호출 순서
	First fir;

	return 0;
}
