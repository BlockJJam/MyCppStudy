#pragma once
#include <iostream>

class Position2D
{
private:
	int _x;
	int _y;

public:
	Position2D(const int & x_in, const int & y_in)
		: _x(x_in), _y(y_in)
	{}
	
	//TODO : overload operator =
	void pos_set(const Position2D pos_target)
	{
		pos_set(pos_target._x, pos_target._y);
	}

	void pos_set(const int & x_target, const int & y_target)
	{
		_x = x_target;
		_y = y_target;
	}

	friend std::ostream & operator << (std::ostream & out, const Position2D & pos2D)
	{
		out << " " << pos2D._x << " " << pos2D._y;
		return out;
	}
};