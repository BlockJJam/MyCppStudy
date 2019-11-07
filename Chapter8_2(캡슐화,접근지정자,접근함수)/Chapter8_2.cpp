#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date
{
private:				// 접근 지정자(public/private/protected) : 어느범위까지 접근 가능한지
	int _month;
	int _day;
	int _year;

public:
	void setDate(const int& month_input, const int& day_input, const int& year_input)
	{
		_month = month_input;
		_day = day_input;
		_year = year_input;
	}

	void setMonth(const int &month_input)
	{
		_month = month_input;
	}

	const int &getDay()		// getter는 const로 참조형태로
	{
		return _day;
	}

	const int &getMonth()		// getter는 const로 참조형태로
	{
		return _month;
	}

	const int &getYear()		// getter는 const로 참조형태로
	{
		return _year;
	}

	void copyFrom(const Date & original)
	{
		_month = original._month;
		_day = original._day;
		_year = original._year;
	}


};

int main()
{
	Date today;
	//today._month = 8;
	//today._day = 4;
	//today._year = 2025;
	today.setDate(8, 4, 2025);
	today.setMonth(2);

	cout << today.getDay() << endl;

	Date copy;
	copy.copyFrom(today);







	return 0;
}
