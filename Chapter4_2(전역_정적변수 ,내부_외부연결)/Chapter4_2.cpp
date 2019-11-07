/*
	static은 다른 cpp파일에서 접근할 수 없다
	전역변수는 다른 파일에서도 접근할 수 있다

	int g_x;				// external linkage
	static int g_x;			// internal linkage	- 다른 cpp파일에서 접근 불가
	const int g_x;			// X

	extern int g_z;			
	extern const int g_z ;	// 다른곳에서 초기화 되있어서 전방선언만 가능

	int g_y(1);					// external linkage
	static int g_y(1);			// internal
	const int g_y(1);			// external

	extern int g_w(1);			// external
	extern const int g_w(1);	// exteranl
*/

#include <iostream>
#include "MyHeader.h"

using namespace std;
//int value = 1;
//static int g_a = 1;

//forward declaration
extern void doSomething();		// 어딘가에 extern(외부)에 doSomething()을 가져다 전방선언했다
extern int a;				// a가 test.cpp에도 선언되어 있고, 전역변수로도 선언되어있다
/*
void doSomething()
{
	static int a = 1;			// static을 이용하면 메모리 공유 , a가 받은 메모리가 static이다 , 
								// OS가 메모리주소를 static에게 한번만 할당(무조건 초기화 필요)하고 다시 호출했을 때 static에
								// 이미 주소를 할당했기 때문에 다시 초기화하지 않는다 즉, 메모리 회수를 바로 하지 않는다
								// 전역변수와의 차이점 : 전역변수는 변경을 통한 사용위험이 너무 높음( 대안 : 어두로g_, 매개변수)
								//						즉, static은 hide해서 무조건적인 접근이 어렵다
	++a;
	cout << a << endl;
}
*/

int main()
{
	int value = 2;

	//전역연산자 ::이용
	//cout << ::value << endl;
	//지역변수 호출
	//cout << value << endl;
	cout << a << endl;

	cout << "In main.cpp " << Constants::pi << " " << &Constants::pi<< endl;	// 헤더 파일에 글로벌변수나 함수를 사용하면
																				// test.cpp의 주소와 다르다 -> 메모리 낭비
																				// MyConstant.cpp를 만들어서 따로 선언을 해서
																				// 가져다 쓸 경우에 메모리를 낭비하지 않음
	doSomething();

	return 0;
}

