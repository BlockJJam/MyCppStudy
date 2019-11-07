#pragma once

#include <iostream>

class Cents
{
private:
	int _cents;

public:
	Cents(int cents)
		: _cents(cents)
	{}

	friend bool operator > (const Cents &c1, const Cents &c2)
	{
		return (c1._cents > c2._cents);
	}

	friend std::ostream& operator << (std::ostream &out, const Cents cents)
	{
		out << cents._cents << " cents ";
		return out;
	}
};