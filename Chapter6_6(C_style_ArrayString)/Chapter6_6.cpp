#include <iostream>

using namespace std;

int main()
{
	char myString[] = "string";				// 6�������� \0�� �������� ���̹Ƿ� 7bytes

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
	
	// ���� C��Ÿ��
	char source[] = "Copy this!";
	char dest[50]{ "", };					// �����÷ο찡 �߻� 

	// strcpy(dest, source);
	// strcat ( ���� ���̱�)
	strcat(dest, source);
	// strcmp ( ���ڿ� ��) ������ 0, �ٸ��� -1
	cout << strcmp(source, dest) << endl;	
	cout << source << endl;
	cout << dest << endl;


	//std::string �� �ξ� ���� ����
	return 0;
}