/*
	string 문자 접근하기와 배열로의 변환
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string my_str("abcdefg");
	
	cout << my_str[0] << endl;
	cout << my_str[3] << endl;

	my_str[3] = 'Z';

	cout << my_str << endl;

	//my_str[100] = 'x';
	//cout << my_str[100] << endl;

	try {
		//my_str[100] = 'x';			// 예외처리를 넣으면 느려짐, 즉 느려질까바 예외처리가 안됨
		my_str.at(100) = 'X';			// 값을 넣으면서 예외 처리가 있는 at() 함수 
	}
	catch (exception &e)				
	{
		cout << e.what() << endl;
	}
	
	const char *arr = my_str.c_str();	// string -> c스타일 로 변경, 뒤에 \0을 붙여서 준다
	cout << int(arr[6]) << endl;
	cout << int(arr[7])<< endl;				// '\0'

	char buf[20];
	
	my_str.copy(buf, 5, 1);				// 두번째 5는 사이즈, 세번째 1은 시작index
	buf[5] = '\0';

	cout << buf << endl;

	return 0;
}