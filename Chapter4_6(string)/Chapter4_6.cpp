#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
	const char my_strs[] = "hello, world";			// c에서 배웠던 것
	const string my_hello = "hello, world";			//string
	const string my_hello1( "hello, world");
	const string my_hello2{ "hello, world" };
	//string my_ID = 123;								// string -> 123 이런형태로는 못바꿈
	cout << my_hello << endl;

	// int를 입력받기
	cout << " your age ? :";
	int age;
	cin >> age;
	// std::cin.ignore(32767, '\n');	// \n을 만날때까지 최대 32767 개의 글자를 무시해라
	std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//string을 입력받기
	cout << " Your Name ? :" ;
	string name;
	std::getline(std::cin, name);

	cout << name << " " << age << endl;

	// 문자열 두개 합치기, 문자열 길이
	string a("Hello,");
	string b("World! ");
	string hw = a + b;				// append

	hw += "I'm good ";
	
	cout << hw << endl;
	cout << a.length() << endl;
	

 
	return 0;
}