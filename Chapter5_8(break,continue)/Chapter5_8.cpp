#include <iostream>

using namespace std;

void breakOrReturn()
{
	while (true)
	{
		char ch;
		cin >> ch;

		if (ch == 'b')
			break;
		if (ch == 'r')
		{
			return;
		}
	}

	cout << "hello" << endl;
}

int main()
{
	for (int i = 0; i < 10; i++)
	{

		cout << i << endl;
		if (i == 5)
			break;
	}
	return 0;
}
