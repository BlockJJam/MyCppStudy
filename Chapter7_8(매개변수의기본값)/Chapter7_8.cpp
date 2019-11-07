/*
	매개변수의 기본값


*/

#include <iostream>
#include <string>

using namespace std;

/*
// 밑은 error!! 정의나 선언 둘 중 하나에만 매개변수 기본값을 설정, header파일의 선언에 기본값을 표준적으로 사용
void print(int x = 10, int y = 20, int z = 0); // in header
void print(int x,int y, int z)		// 기본값이 모두 있거나 없을 수 있고, 1개만 2개만 있을 수 있지만, 오른쪽 매개변수부터 채워져야 한다
{
	cout << x << endl;
}
*/
// 함수 오버로딩과 함께 일때의 모호성으로 인한 Error
// 가능
void print(string str) {}
void print(char ch = ' '){}
// 불가능
void print_int(int x) {}
void print_int(int x, int y = 10) {}


int main()
{
	print();		// 두번 째 print로 감
	print_int(10);	// 고를수 없음
	return 0;
}