/*
	단항연산자 오버로딩 하기
	int a;
	cout << -a << endl; <- 이런 형태
*/

#include <iostream>

using namespace std;

class Cents
{
private:
	int _cents;
public:
	Cents(int cents = 0) { _cents = cents; }
	int getCents() const { return _cents; }
	int& getCents() { return _cents; }

	// -단항
	Cents operator - () const
	{
		return Cents(-_cents);
	}
	// !단항
	bool operator ! () const
	{
		return (_cents == 0) ? true : false;
	}

	friend std::ostream& operator << (std::ostream &out, const Cents cents)
	{
		out << cents._cents;
		return out;
	}

};

int main()
{
	Cents cents1(6);
	Cents cents2(0);

	// -단항
	cout << cents1 << endl;
	cout << -cents1 << endl;
	cout << -Cents(-10) << endl;

	// ! 단항
	auto temp = !cents1;		// bool로 잡힌다

	cout << !cents1 << " " << !cents2 << endl;
	return 0;
}