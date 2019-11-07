/*
	이동의 의미와 스마트 포인터
		-> 스마트 포인터 : 기존의 일반 포인터는 메모리 해제를 따로 해줘야 된고, 영역에 따라 메모리해제를 놓치는 경우가 있음
						 : 그러나 "스마트 포인터"를 사용하면 영역을 벗어나면 알아서 메모리 해제

*/

#include "Resource.h"
#include "AutoPtr.h"

using namespace std;

// RAII : 자원을 new 한 곳에서 delete해줘야 한다
void doSomething()
{
	try
	{
		//Resource *res = new Resource;					// dull(멍청한) pointer
		AutoPtr<Resource> res (new Resource);			// smart pointer

		return;

		// work with res
		if (true)
		{
			throw - 1;;									// delete가 안되자나? -> smartpointer 사용해라
		}
		//delete res;
	}
	catch (...)
	{

	}
	return;												// 전적으로 메모리관리를 프로그래머에게 말고 컴파일러에게 넘기자 -> class 생성
}

int main()
{
	//doSomething();

	{
		AutoPtr<Resource> res1(new Resource);
		AutoPtr<Resource> res2;

		cout << std::boolalpha;

		cout << res1._ptr << endl;
		cout << res2._ptr << endl;

		res2 = res1;					// 제목 이동의 의미( move semantics -> semantic<의미적> )

		cout << res1._ptr << endl;
		cout << res2._ptr << endl;		// new Resource 로 메모리를 한번만 초기화
										// 영역을 벗어나면 res1, res2 두번 메모리 해제 발생 runtime err
										// 해결방안 : res2가 res1의 소유권을 가져와버리기(res1 권한박탈)
		
		doSomething(res2);				// 또 다른 문제점: auto pointer가 함수 파라미터로 들어갔을 때 함수사용후 포인터가 메모리 해제됨  
	}
	
	// value semantics		( copy semantics )
	// reference semantics	( pointer )
	// move semantics		( move )

										
	return 0;
}