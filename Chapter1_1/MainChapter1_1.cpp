#include <iostream>
/* 
< 프로그램 구조, 주석 >
main 함수는 return을 하게 되면, 누구에게 주느냐? OS에게 준다
statement는 ' 명령문 '이라고 생각하면 된다
x=2; <- 2는 리터럴literal
#include <- 전처리기  preprocessor directive
std::cout .... <- std는 namespace (cout이라는 함수가 정의된 곳) <<는 output 오퍼레이터

객체는 의미있는 정보를 메모리에 저장하는데 이 메모리의 위치를 가리키는것
 */
int main()
{
	std::cout << "This is chapter11" << std::endl;

	return 0;
}