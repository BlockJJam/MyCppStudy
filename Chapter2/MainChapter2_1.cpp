//void : 저장을 하지 않는 빌트인 타입

#include <iostream>

int main()
{
	using namespace std;

	bool bValue = true;
	char chValue = 65;
	float fValue = 3.141592f;
	double dValue = 3.141592;

	// auto 타입 : int,char,double 과 float 사이가 애매할 때 modern C++에서 나온 새로운 부동소수점 타입
	auto aValue = 3.141592;
	auto aValue2 = 3.141592f;
	auto aValue3 = 'A';
	cout << fValue << endl;
	cout << sizeof(aValue) << endl;
	cout << sizeof(aValue2) << endl;
	cout << aValue3 << endl;

	//변수 초기화 3가지 방법
	int i = 0;			// copy initialization
	int a(0);			// direct initialization
						//int a(3.14); <- 경고 
	int b{ 123 };		// uniform initialization  객체지향에서 중요
						//int b{ 4.5 }; <- 에러 , uniform 이 좀더 엄격
						// 즉, copy와 direct 초기화는 부동소수점을 넣어도 컴파일이 가능, uniform은 불가능

	int k, 1, m = 123;	// 가능은 한데 초기화 스타일은 맞춰줘라 누군 초기화해주고, 누군 안해주는 식은 X


	return 0;

}