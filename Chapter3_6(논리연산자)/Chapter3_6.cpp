#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	
	return 0;
}

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	// De Morgan's Law
	bool x = true;
	bool y = false;

	bool a= !(x || y);
	bool b = !x || !y;
	cout << a << " " << b <<endl;
	int num1 = 1;
	int num2 = 2;
	if (num1 == num2)
		cout << "what" << endl;
	else
		cout << "the" << endl;
	return 0;
}