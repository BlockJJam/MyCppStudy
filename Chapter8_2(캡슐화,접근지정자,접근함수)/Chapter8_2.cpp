#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date
{
private:				// ���� ������(public/private/protected) : ����������� ���� ��������
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

	const int &getDay()		// getter�� const�� �������·�
	{
		return _day;
	}

	const int &getMonth()		// getter�� const�� �������·�
	{
		return _month;
	}

	const int &getYear()		// getter�� const�� �������·�
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
