/*
< 키워드(예약어)와 식별자 이름짓기 >

override, final <- C+11버전
transaction_safe, transaction_safe_dynamic <- TM TS

잘 알고 있듯이 함수명은 동사형, 변수명은 명사형
앞에 _apples 같이 접두어 _를 사용하는 것은
  1. OS의 시스템 프로그래밍을 사용할 때
  2. 객체지향의 클래스의 멤버를 선언할 때( 굳이 요즘 사용안함 선언부로 바로갈수 있으니까)

*/
#include <iostream>
using namespace std;

int addNumber() //...........
{
	return;
}

int main()
{
	addNumber();

	return;
}