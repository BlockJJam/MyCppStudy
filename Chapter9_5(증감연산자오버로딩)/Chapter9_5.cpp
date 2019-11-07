/*
	���������� �����ε�
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

	// prefix(����)
	Digit & operator ++ ()
	{
		++_digit;
		return *this;
	}

	// suffix(����)	-> ()�ȿ� Ÿ���� ���� ����
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