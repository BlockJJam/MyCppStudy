#include <iostream>

int main()
{
	using namespace std;

	float pi = 3.14f;			// 뒤에 f가 없으면 double로 판단
	int i = -1234u;				// 뒤에 u가 붙으면 unsigned로 판단
	int l = 12324LL;			// 캐스팅이 더 명확히 알 수 있다

	cout << pi << " " << i << " " << l << endl;

	int x = 0b10;				// 어두로 0은 8진수 0x는 16진수 0b는 이진수

	// 이진수에서 '는 컴파일러가 신경안씀
	x = 0b1000'1111'1000'0101;
	cout << x << endl;
	
	// 리터럴 상수를 코드에 넣고 싶으면 의미를 갖는 이름으로 만들어놓는다
	const int price_per_item = 10;
	int num_items = 123;
	int price = num_items * price_per_item;
	cout << "price:  " <<price << endl;

	return 0;
}