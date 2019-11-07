/*
	string 대입 교환 덧붙이기 삽입
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1("one");

	string str2;
	str2 = str1;
	str2 = "two";
	str2.assign("two").append("three");
	str2 += " three";
	//cout << str2 << endl;
	str2 = "two";

	cout << str1 << " " << str2 << endl;

	swap(str1, str2);
	
	cout << str1 << " " << str2 << endl;

	str1.swap(str2);

	cout << str1 << " " << str2 << endl;

	str1.push_back('A');	// append를 한글자만

	cout << str1 << " " << str2 << endl;

	str1 = "aaaa";

	str1.insert(2, "bbb");

	cout << str1 << " " << str2 << endl;

	return 0;
}