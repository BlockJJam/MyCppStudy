#include <iostream> // cout, cin, endl,...
#include <cstdio> // printf
using namespace std;

/* 

 < 표준 입출력 >
std::를 사용하기 번거롭다 . -> using namespace std; 사용

*/
int main()
{
	int x = 1024;
	double pi = 3.12121212;

	cout << "i love this lecture!" << endl;
	cout << "x is " << x << "pi is " << pi << endl;

	//탭: \t, 줄바꿈 : \n, 오디오 소리 : \a
	cout << "abc" << "\t" << "def" << endl;

	cout << "before y is 0 input y : " ;
	int y = 0;
	cin >> y;
	cout << "Your input is " << y << endl;
	return 0;
}