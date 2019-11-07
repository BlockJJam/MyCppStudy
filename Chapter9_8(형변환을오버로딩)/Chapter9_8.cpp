/*
	형변환을 오버로딩 하기
		-> 타입 캐스팅관련
*/

#include <iostream>

using namespace std;

class Cents
{
private:
	int _cents;
public:
	Cents(int cents = 0)
	{
		_cents = cents;
	}

	int getCents()
	{
		return _cents;
	}
	void setCents(int cents)
	{
		_cents = cents;
	}

	operator int()
	{
		cout << "cast here" << endl;
			return _cents;
	}
};

class Dollar
{
private:
	int		_dollars = 0;
public:
	Dollar(const int& input)
		: _dollars(input)
	{}

	operator Cents()
	{
		return Cents(_dollars *100);
	}
};

void printInt(const int &value)
{
	cout << value << endl;
}

int main()
{
	// 전부 오버로딩한 캐스트를 사용함
	Cents cents(7);
	int value = (int)cents;
	value = int(cents);
	value = static_cast<int>(cents);

	printInt(cents);

	Dollar dol(2);
	cents = dol;
	
	printInt(cents);


	return 0;
}