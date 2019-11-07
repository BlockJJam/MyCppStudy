#include <iostream>
#include <cmath>
#include <limits>

int main()
{
	using namespace std;

	short s = 1;
	int i = 1;
	long l = 1;
	long long ll = 1;

	cout << pow(2, sizeof(long long) * 8 -1) << endl;
	cout << std::numeric_limits<long long>::max() << endl;
	cout << std::numeric_limits<long long>::min() << endl;
	cout << std::numeric_limits<long long>::lowest() << endl;

	s = 32767;
	s = s + 1;
	cout << 22/4.0 << endl;
	return 0;
}