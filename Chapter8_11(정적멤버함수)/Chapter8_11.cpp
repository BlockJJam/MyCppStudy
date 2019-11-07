/*
	정적멤버 함수
*/

#include <iostream>

using namespace std;

class Something
{
public:
	//inner class로 static 멤버변수 초기화
	class _init
	{
	public:
		_init()
		{
			s_value = 9874;
		}
	};

private :
	static int s_value;
	int m_value;

	static _init s_initializer;

public:
	Something()
		: m_value(123)			// 불가능! static 멤버변수는 생성자 초기화에 들어갈 수 없음 -> 돌려서는 가능
	{}

	static int getValue()		// static 함수는 this를 못쓴다 
	{
		return s_value;
		//return m_value;		<- 안됨 왜? 정적 함수는 정적 멤버에 접근이 가능
	}

	int temp()
	{
		return this->s_value;
	}
};

int Something::s_value = 1024;;
Something::_init Something::s_initializer;

int main()
{ 
	cout << Something::getValue() << endl;

	Something s1,s2;
	cout << s1.getValue() << endl;
	//cout << s1.s_value << endl;

	int (Something::*fptr1)() = &Something::temp;		// class의 각 함수는 객체마다 고유의 주소를 갖는 것이 아니라 class안에서 하나의 주소만을 가짐

	cout << (s2.*fptr1)() << endl;

	int (*fptr2)() = &Something::getValue;				// static멤버함수는? 특정 인스턴스와 상관없이 실행 시킬수 있기때문에 앞에 Class타입을 설정 안해줘도 된다



	return 0;
}
