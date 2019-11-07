/*
	string stream
*/

#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	stringstream os;

	
	//os << "hello, world ";		// << : insertion operator, >> : extraction operator
	////os.str("hello, world!");	// os.str(...) : 아예 ...으로 바꿔버림( 추가로 흘러가는것이 아님), parameter가 없으면 그냥 os값을 리턴
	//os << "hello, world2" << endl;
	//string str;

	//str = os.str();

	//cout << str << endl;
	//cout << os.str()<< endl;
	/*int i = 12345;
	double d = 67.89;*/

	//숫자 넣기
	//os << i << " " << d;;

	/*string str1;
	string str2;
	
	os >> str1 >> str2;

	cout << str1 << "  |  " << str2 << endl;*/

	// 숫자로 받기

	os << "12345 678.90";

	/*int i2;
	double d2;
	os >> i2 >> d2;*/
	//cout << i2 << " | " << d2 << endl;

	// stream 비우기
	os.str("");
	os.clear();				// state 까지 초기화
	os << "hello";

	
	cout << os.str() << endl;
	return 0;
}