/*
	증감연산자 오버로딩
*/

#include <iostream>

using namespace std;

class Digit
{
private:
	int _digit;
public:
	Digit(int digit = 0)
		: _digit(digit)
	{}

	// prefix(전위)
	Digit & operator ++ ()
	{
		++_digit;
		return *this;
	}

	// suffix(후위)	-> ()안에 타입이 들어가면 후위
	Digit & operator ++ (int)
	{
		Digit temp(_digit);
		++(*this);

		return temp;
	}

	friend std::ostream& operator << (std::ostream &out, const Digit digit)
	{
		out << digit._digit;
		return out;
	}

};

int main()
{
	Digit d(5);
	cout << ++d << endl;
	cout << d << endl;

	cout << d++ << endl;
	cout << d << endl;

	return 0;
}