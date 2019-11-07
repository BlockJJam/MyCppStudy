#include <iostream>

using namespace std;

int main()
{
	char myString[] = "string";				// 6글자지만 \0이 마지막에 쓰이므로 7bytes

	char myString1[255]{ '0', };

	//cin >> myString1;

	//myString1[0] = 'a';
	//myString1[5] = '\0';
	//cin.getline(myString1,255);
	//cout << myString1 << endl;

	int ix = 0;
	while (true)
	{
		if (myString1[ix] == '\0')break;

		cout << myString1[ix] << " " << (int)myString1[ix] << endl;
		++ix;
	}

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	
	// 고전 C스타일
	char source[] = "Copy this!";
	char dest[50]{ "", };					// 오버플로우가 발생 

	// strcpy(dest, source);
	// strcat ( 문자 붙이기)
	strcat(dest, source);
	// strcmp ( 문자열 비교) 같으면 0, 다르면 -1
	cout << strcmp(source, dest) << endl;	
	cout << source << endl;
	cout << dest << endl;


	//std::string 이 훨씬 쓰기 좋다
	return 0;
}