/*
	입출력 연산자 오버로딩
*/

#include <iostream>
#include <fstream>

using namespace std;

class Point
{
private:
	double _x, _y, _z;

public:
	Point(double x = 0.0, double y = 0.0, double z = 0.0)
		:_x(x), _y(y), _z(z)
	{}

	double getX() { return _x; }
	double getY() { return _y; }
	double getZ() { return _z; }

	// 입출력 연산자 오버로딩 안한 버전
	/*void print()
	{
		cout << _x << " " << _y << " " << _z << endl;
	}*/

	// 입출력 연산자 이용버전
	friend std::ostream& operator << (std::ostream &out, const Point &point)
	{
		out << "( " << point._x << " " << point._y << " " << point._z << " )";

		return out;
	}

	friend std::istream& operator >> (std::istream &in, Point &point)
	{
		in >> point._x >>  point._y >> point._z ;

		return in;
	}

};

int main()
{
	ofstream of("out.txt");

	//Point p1(0.3, 0.1, 0.2) ,p2(3.4, 4.5, 2.0);
	Point p1, p2;
	
	cin >> p1 >> p2;

	//p1.print();
	//cout << " ";
	//p2.print();
	//cout << " ";

	cout << p1 << " " << p2 << endl;
	of << p1 << " " << p2 << endl;

	//of.close();

	return 0;
}