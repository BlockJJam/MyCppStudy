#pragma once

#include <string>
#include "Position2D.h"

using namespace std;

class Monster
{
private:
	string _name;
	Position2D _location;				// composition relation, monster의 서브클래스

public:
	Monster(const string name_in, const Position2D & pos_in)
		: _name(name_in), _location(pos_in)
	{}

	void moveTo(const Position2D & pos_target)
	{
		_location.pos_set(pos_target);
	}

	friend std::ostream & operator << (std::ostream & out, const Monster monster)
	{
		out << monster._name << " " <<  monster._location;
		return out;
	}
};