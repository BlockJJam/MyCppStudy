#include <iostream>
#include <typeinfo>		// 내가 원하는 변수의 타입정보를 확인가능한 LIB
#include <iomanip>
int main()
{
	using namespace std;

	int a = 123.0;
	cout << typeid(a).name() << endl; // 경고표시 : "double'에서 'int'(으)로 변환하면서 데이터가 손실될 수 있습니다"

	double b = 0.123456789;
	float c = b;		// numeric promotion 작은 크기타입에서 큰 크기 타입으로는 갈수 있음, 반대로는 값이 범위를 넘어가면 캐스팅 X

	cout << std::setprecision(12) << c << endl;

	short d = c;
	cout << d << endl;

	int i = 3000;
	char i_char = i;
	cout << static_cast<int>(i_char) << endl;

	//numeric conversion
	cout << static_cast<unsigned int>(5u - 10u); // <- unsigned int가 int보다 우선순위가 높음
	
	// int, unsigned int, long, unsigned long, long long, unsigned long long ,float, double, long double

	// 명시적 변환
	int i = (int)4.0;	// C 스타일
	int i = int(4.0);	// C++ 스타일
	int i = static_cast<int>(4.0);	// 최신형




	return 0;

}