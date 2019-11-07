/*
	Null Pointer
	 => 포인터주소에 쓰레기값이 들어가 있으면 de-ref할 때 엉뚱한 곳의 값을 가져올 수 있기 때문에 OS가 경고를 함
	 => 위의 이유를 방지하기 위해 사용하는  NULL Pointer사용

*/
#include <iostream>
#include <cstddef>


using namespace std;

void doSomething(double *ptr)
{
	cout << "address of pointer variable in main() " << &ptr << endl;
	if (ptr != nullptr)
	{
		cout << *ptr << endl;
	}
	else
	{
		cout << "Null ptr, do nothing " << endl;
	}
}
int main()
{
	// null pointer - modern C++
	double *ptr_d = nullptr;
	
	doSomething(ptr_d);
	doSomething(nullptr);

	double d = 123.4;
	ptr_d = &d;
	doSomething(&d);
	doSomething(ptr_d);
	
	nullptr_t nptr;		// 파라미터에 nullptr타입만 받을 때 사용한다
	
	// 포인터 변수의 주소는?
	cout << "address of pointer variable in main() " << &ptr_d << endl;			// 즉, 파라미터는 복사형태이므로, 포인터변수 주소와 파라미터 포인터 변수 주소는 서로 다르다
	doSomething(ptr_d);

	return 0;
}