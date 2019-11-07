// float -> 4, double -> , long double -> 8~16 4바이트기준 맨앞부터 1비트 : 부호, 8비트: 지수 , 23비트 : 가수

#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	float f(3456789.0f);
	double d(1.0);
	long double ld;

	cout << numeric_limits<float>::lowest() << endl;
	cout << numeric_limits<double>::lowest() << endl;
	cout << numeric_limits <long double> ::lowest() << endl;

/*
	cout << std::setprecision(16) << endl;
	cout << 1.0 / 3.0 << endl;
	cout << f << endl;
*/
	cout << d << endl;
	/*cout << std::setprecision(17);*/
	cout << d << endl;

	double d1(1.0);
	double d2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);

	cout << setprecision(17);
	cout << d1 << endl;
	cout << d2 << endl;

	double zero = 0.0;
	double posinf = 5.0 / zero;
	double neginf = -5.0 / zero;
	double nan = zero / zero;
	cout << posinf << " " << std::isinf(posinf) << endl; // inf : infinite
	cout << neginf << " "  << std::isinf(neginf) << endl;
	cout << nan << " " << isnan(nan)  << endl;  // nan(ind)
	cout << 1.0 << " " << isnan(1.0) << endl;

	return 0;
}