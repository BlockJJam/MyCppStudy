#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
	for (int count = 0; count < argc; ++count)
	{
		string argv_single = argv[count];

		if (count == 1)
		{
			int input_number = stoi(argv_single);
			cout << input_number + 1 << endl;
		}
		else
			cout << argv_single << endl;

		cout << argv_single << endl;
	}
	// (��ǥ��)Boost lib - program options => Ŀ������ argumentó���� ���� ���
	return 0;
}