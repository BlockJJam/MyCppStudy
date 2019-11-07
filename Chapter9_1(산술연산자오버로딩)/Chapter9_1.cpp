/*
	산술 연산자 오버로딩 하기
		-> 주의해야 할 점 : ( ?:(삼항) , ::(범위연산자), sizeof, .(멤버 셀렉션?), .*(멤버포인터셀렉션?) 은 안됨
							^ 우선순위가 매우 낮기 때문에 오버로딩 안하는게 좋음
*/

#include <iostream>

using namespace std;

class Cents
{
private:
	int _cents;
public:
	Cents(int cents = 0) { _cents = cents; }
	int getCents() const { return _cents; }
	int& getCents() { return _cents; }

	friend Cents operator +(const Cents &c1, const Cents &c2)		// friends 함수
	{
		return (c1.getCents() + c2.getCents());
	}

	Cents operator -( const Cents &c2)								// 멤버 함수로 산술연산자 오버로딩
	{
		return (this->_cents + c2.getCents());
	}
	// 멤버로만 해야되는 연산자 ( = ,[...] , (...), -> 
};

// 산술 연산자 없는 버전
Cents add(const Cents &c1, const Cents &c2)		// 요즘엔 반환 매개변수를 두지 않고 반환 타입을 사용
{
	return (c1.getCents() + c2.getCents());
}

// 산술 연산자 operater 이용
//Cents operator +(const Cents &c1, const Cents &c2)		
//{
//	return (c1.getCents() + c2.getCents());
//}

int main()
{
	Cents cents1(6);
	Cents cents2(8);

	/*Cents sum;
	add(cents1, cents2, sum);*/

	cout << add(cents1,cents2).getCents() << endl;		// add도 없애고 싶다
	cout << (cents1 + cents2 + Cents(6)).getCents() << endl;	// 익명객체를 사용해서 6도 더하고 싶다
	// getCents()도 없애고 싶다
	cout << (cents1 + cents2 + Cents(6) + Cents(100)).getCents() << endl;
	
	return 0;
}