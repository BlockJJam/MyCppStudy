/*
	Pointer

	지역변수는 !스택 메모리를 사용
	동적 할당 메모리는 !힙 메모리를 사용

	메모리 주소를 담는 변수를 Pointer라 한다( 레퍼런스와 다른 개념 )
	
	de-reference operator -> 포인터와 다른개념
		==> 포인터가 " 저쪽 주소에 가면 이 데이터가 있다 "라는 간접적인 접근
		==> de-reference는 " 그럼 거기에 진짜 무엇이 있는지 내가 들여다볼게"라는 직접적인 접근

	포인터를 왜 쓸까?
		=> 용도 1) 예를 들어, array를 생각해보자 ,데이터가 100만개가 들어있고 array를 parameter로 넘긴다면, 100만개를 복사하여 넘어가기 때문에 성능저하!
		=> 포인터를 쓰면 array의 메모리 첫 주소만 알려주면 끝
		=> 용도 2) 변수를 여기저기서 쓰면 여기저기 복사해서 쓸 바엔 포인터 첫 주소만 계속 넘기면 복사할 필요가 없다

	

*/

#include <iostream>

using namespace std;

struct Something
{
	int a,b,c,d;
};

int main() 
{
	int x = 5;
	double d = 1.0;

	cout << x << endl;
	cout << (&x) << endl;

	//de-reference operator (*)

	cout << *(&x) << endl;

	// -----   pointer   -----
	int *ptr_x ;
	double *ptr_d = &d;				//16진수로 직접적으로 선언은 안되는데 돌려서 우회하여 사용은 가능
	//typedef int* pint; int의 포인터 타입을 정의


	
	
	cout << sizeof(x) << endl;		
	cout << sizeof(&x) << "," << sizeof(ptr_x) << endl;
	cout << sizeof(d) << endl;
	cout << sizeof(&d) << "," << sizeof(ptr_d) << endl;

	Something ss;
	Something *ptr_ss;

	cout << sizeof(Something) << endl;				// 16bytes
	cout << sizeof(ptr_ss) << endl;					// 4bytes

	// C++의 포인터 문제가 자주 일어나는게 두려울 때
	cout << ptr_x << endl;							// 쓰레기 값이 들어가있고(ptr_x에) 내 프로그램이 사용하지 않는 메모리주소를 가져다 쓸 수도 있는격




	return 0;
}