/*
	istream으로 입력받기
*/

#include <iostream>
#include <string>
#include <iomanip>							// input/output manipulators
using namespace std;

int main()
{
	//char buf[10];

	//cin >> setw(5) >> buf;				// setw(num) 글자수 만큼만 입력받겠다(마지막 글자는 \0)
	//cout << buf << endl;
	//
	//cin >> setw(5) >> buf;
	//cout << buf << endl;
	
	/*char chr;
	while (cin.get(chr))					// while(cin >> ch)빈칸 무시
		cout << ch;*/

	/*int i;
	float f;
	cin >> i >> f;
	cout << i << " " << f << endl;*/

	//char buf[5];
	//cin.getline(buf, 5);					// getline은 마지막에 \n 줄바꿈까지 읽음
	//cin.gcount();							// cin으로 몇글자 읽어 들였나
	//cout << cin.gcount() << " "<< buf << endl;

	//cin.getline(buf, 5);
	//cout << cin.gcount() << " " << buf << endl;

	//string buf;

	//getline(cin, buf);
	//cout << cin.gcount() << " " << buf << endl;		// cin으로 입력받은게 아니라서 count 0

	char buf[1024];

	//cin.ignore(2);							// cin.ignore() : 입력받을 때 한글자 무시, ()안에 숫자 넣으면 숫자만큼 무시

	cout << (char)cin.peek() << endl;		// 가장 읽어올 글자만 출력만

	cin >> buf;
	cout << buf << endl;

	//cin.unget();							// unget() :마지막 글자를 버퍼에 다시 넣어버림
	cin.putback('A');						// putback() : 괄호안의 글자를 버퍼에 넣어버림

	cin >> buf;
	cout << buf << endl;			

	return 0;
}