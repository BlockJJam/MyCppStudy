#include <iostream>

using namespace std;

int main()
{
	int selection;

	do 
	{
		cout << "1. add" << endl;
		cout << "2. sub " << endl;
		cout << "3. mul " << endl;
		cout << "4. div " << endl;
		cout << "Choose Option(1-4) : ";
		cin >> selection;
	} while (selection >= 5 || selection <=0);

	cout << "You selected " << selection << endl;
	return 0;
}