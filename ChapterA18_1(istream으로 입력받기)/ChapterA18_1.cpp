/*
	istream���� �Է¹ޱ�
*/

#include <iostream>
#include <string>
#include <iomanip>							// input/output manipulators
using namespace std;

int main()
{
	//char buf[10];

	//cin >> setw(5) >> buf;				// setw(num) ���ڼ� ��ŭ�� �Է¹ްڴ�(������ ���ڴ� \0)
	//cout << buf << endl;
	//
	//cin >> setw(5) >> buf;
	//cout << buf << endl;
	
	/*char chr;
	while (cin.get(chr))					// while(cin >> ch)��ĭ ����
		cout << ch;*/

	/*int i;
	float f;
	cin >> i >> f;
	cout << i << " " << f << endl;*/

	//char buf[5];
	//cin.getline(buf, 5);					// getline�� �������� \n �ٹٲޱ��� ����
	//cin.gcount();							// cin���� ����� �о� �鿴��
	//cout << cin.gcount() << " "<< buf << endl;

	//cin.getline(buf, 5);
	//cout << cin.gcount() << " " << buf << endl;

	//string buf;

	//getline(cin, buf);
	//cout << cin.gcount() << " " << buf << endl;		// cin���� �Է¹����� �ƴ϶� count 0

	char buf[1024];

	//cin.ignore(2);							// cin.ignore() : �Է¹��� �� �ѱ��� ����, ()�ȿ� ���� ������ ���ڸ�ŭ ����

	cout << (char)cin.peek() << endl;		// ���� �о�� ���ڸ� ��¸�

	cin >> buf;
	cout << buf << endl;

	//cin.unget();							// unget() :������ ���ڸ� ���ۿ� �ٽ� �־����
	cin.putback('A');						// putback() : ��ȣ���� ���ڸ� ���ۿ� �־����

	cin >> buf;
	cout << buf << endl;			

	return 0;
}