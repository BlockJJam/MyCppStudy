#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int x, y;
	cin >> x >> y;
	cout << "your input values are : " << x << y << endl;

	// 부동소수점 비교
	double d1(100 - 99.99);
	double d2(10 - 9.99);

	if (d1 == d2)
		cout << "equal" << endl;
	else if (d1 > d2)
		cout << "d1 win" << endl;
	else if (d2 > d1)
		cout << "d2 win " << endl;
	else
		cout << "not equal" << endl;

	cout << abs(d1-d2) << endl;
	
	// 어느 아주 작은 차이는 같다고 해주자
	const double epsilon = 1e-17;
	if (std::abs(d1 - d2) < epsilon)
		cout << " Approximately equal" << endl;
	else
		cout << " Not equal" << endl;

	return 0;
}