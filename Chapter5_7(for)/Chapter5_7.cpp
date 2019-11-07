#include <iostream>

using namespace std;


int my_pow(int base, int exponent )
{
	int result = 1;

	for (int count = 0; count < exponent; ++count)
		result *= base;


	return result;
}

int main()
{
	int count = 0;
	for (; count < 10; ++count)
		cout << count << endl;

	// for(;;count++) == while(true)


	cout << count << endl;

	cout << my_pow(2, 4) << endl;

	for (int count = 9; count >= 0; count--)
	{
		cout << count << endl;
	}

	for (int i = 0, j = 0; (i+j) < 10; ++i, j+=2)
	{
		cout << i << " " << j << endl;
	}

	

	return 0;
}