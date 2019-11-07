#include <iostream>

void my_function()			// return 없을 때
{

}

int main()
{
	using namespace std;
	//void my_void;
	int i = 123;
	float f = 123.456f;
	void *my_void;

	my_void = (void*)&i;				// void 캐스팅이 가능한 이유 : 데이터 주소를 표현하는 타입은 같다
	cout << my_void << endl;
	my_void = (void*)&f;
	cout << my_void << endl;

	return 0;

}