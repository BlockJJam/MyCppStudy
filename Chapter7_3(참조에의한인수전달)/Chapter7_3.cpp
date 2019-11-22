#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void addOne(int &y)
{
	y = y + 1;
	cout << y << " " << &y << endl;
}

void getSinCos(const double &degrees, double&sin_out, double &cos_out)		// const 입력, 참조&는 출력
{
	static const double pi = 3.141592 / 180.0;	// 함수 사용될 때마다 메모리를 잡는게 아닌 한번 잡고 쭉 이용
	double radians = degrees * pi;
	sin_out = sin(radians);
	cos_out = cos(radians);
}

void foo(const int &x)				// Modern C++ 입력인자는 변경 X되게(Const int &) 반환은 여러개가 나오는게 가능해짐
{
	cout << x << endl;
}


// void foo2(int* &ptr)
typedef int* pint;
void foo2(pint ptr)
{
	cout << ptr << " " << &ptr << endl;
}

// array param
//void printElements(int(&arr)[4])
void printElements(vector<int> &arr)
{

}

int main()
{
	int x = 6;
	cout << x << " " << &x << endl;

	addOne(x);

	cout << x << " " << &x << endl;

	double sin(0.0);
	double cos(0.0);
	
	getSinCos(30.0 ,sin, cos);

	cout << sin << " " << cos << endl;

	//참조매개변수에 실인자를 보내면 주소가 없으므로 오류, const를 함수 매개변수를 바꿔주면 가능
	foo(6);

	//포인터에 대한 레퍼런스를 매개변수로도 가능

	x = 5;
	pint ptr = &x;
	cout << ptr << " " << &ptr << endl;

	foo2(ptr);

	// array를 parameter로 전달하는 방법
	//int arr[]{ 1,2,3,4 };
	vector<int> arr{ 1,2,3,4 };
	printElements(arr);

	return 0;
}