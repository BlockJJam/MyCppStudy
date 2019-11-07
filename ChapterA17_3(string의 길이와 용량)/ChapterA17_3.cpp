/*
	string의 길이와 용량이 별도로 운영

*/

#include <iostream>
#include <string>

using namespace std;

int main()
{	
	string my_str("01234567");				// string은 뒤에 '\0'을 가지지 않는다, string은 클래스니까 길이를 직접 가지고 있어서 끝났는지 확인이 바로 가능
	my_str.reserve(1000);					// 1000개의 자리를 잡아놓기
	cout << std::boolalpha << endl;
	cout << my_str.length() << endl;
	cout << my_str.size() << endl;
	cout << my_str.capacity() << endl;		// 용량만큼은 새로 할당 안받아도 된다
	cout << my_str.max_size() << endl;


	return 0;
}