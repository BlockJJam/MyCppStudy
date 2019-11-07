/*
	동적 메모리할당

	1) static  : 전역,정적 메모리 할당  
	2) 자동 메모리할당 : 블럭 안에서만 메모리 할당
	3) 동적 메모리할당 : 필요시 실행 시간 동안에만 사용하는 메모리 할당
*/

#include <iostream>

using namespace std;

int main()
{
	int array[10000];		// stack 상대적으로 작은 크기 <-> 동적(힙)메모리 상대적으로 큰 크키
	new int;				// int 사이즈 os에게 받고 

	int *ptr = new (std::nothrow) int{ 7 };		// ==int var; var= 7; 
									// std::nothrow는 메모리 오류가 발생한다면 예외처리로 가지 않고 메모리 확보시 할ㄷㅇ

	cout << ptr << endl;
	cout << *ptr << endl;

	delete ptr;						// 이게 없으면 프로그램 종료시에 OS가 걷어감
	ptr = nullptr;					// delete 메모리 반납은 1) 프로그래머가 신경써서 잘 반납 2) 스마트 포인터에서 기능 사용

	cout << "After delete" << endl;
	if (ptr != nullptr)
	{
		cout << ptr << endl;
		cout << *ptr << endl;			// 메모리 반환되서 엉뚱한 값을 출력
	}
	else
	{
		cout << "Could not allocate memory" << endl;
	}

	// memory leak
	while (true)
	{
		int *ptr = new int;				// 말도 안되는 이유 : 이런 코딩이 쓰일 일이 없다
		cout << ptr << endl;

		delete ptr;						// new - delete 조합은 느림 -> OS 거쳐서 와야함				
	}



	return 0;
}