#include <iostream>


bool isEqual(int a, int b)
{
	bool result = (a == b);
	return result;
}

int main()
{
	using namespace std;

	bool b1 = true;
	bool b2(false);
	bool b3{ true };
	b3 = false;

	cout << std::boolalpha;
	cout << !b1 << endl;
	cout << !b2 << endl;
	cout << (true || true) << endl;

	if (true)
		cout << "this is true" << endl;
	else
		cout << "this is false " << endl;

	cout << isEqual(1, 1) << endl;
	cout << isEqual(0, 3) << endl;

	if (5)
	{
		cout << "tr" << endl;
	}
	else
		cout << "fa" << endl;
	
	bool b;
	cin >> b;
	cout << "your input : " << b << endl;

	return 0;
}