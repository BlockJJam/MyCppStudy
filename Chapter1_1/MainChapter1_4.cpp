#include <iostream> // cout, cin, endl,...
#include <cstdio> // printf
using namespace std;

/* 

 < ǥ�� ����� >
std::�� ����ϱ� ���ŷӴ� . -> using namespace std; ���

*/
int main()
{
	int x = 1024;
	double pi = 3.12121212;

	cout << "i love this lecture!" << endl;
	cout << "x is " << x << "pi is " << pi << endl;

	//��: \t, �ٹٲ� : \n, ����� �Ҹ� : \a
	cout << "abc" << "\t" << "def" << endl;

	cout << "before y is 0 input y : " ;
	int y = 0;
	cin >> y;
	cout << "Your input is " << y << endl;
	return 0;
}