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
	// (준표준)Boost lib - program options => 커멘드라인 argument처리에 많이 사용
	return 0;
}