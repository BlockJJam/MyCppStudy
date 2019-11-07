/*
	문자열 심볼릭상수( C 스타일 )
*/

#include <iostream>

using namespace std;

const char* getName()
{
	return "Jackjack";
}

int main()
{
	//char *name = "Jack jack";	-> Error : 오른쪽은 리터럴, 실제로 어디 담길지 정해지지 않고, 포인터는 데이터가 담겨진 메모리 시작주소만 가르킨다
	const char *name = getName();			// 기호적인 상수처럼 사용가능
	const char *name2 = getName();
	cout << name << endl;
	cout << (uintptr_t)name << endl;		// name과 name2가 같은 주소를 갖는 이유: 같은 문자열이니깐 같은 메모리 공유해서 써라 
	cout << (uintptr_t)name << endl;		// name과 name2가 다른 주소를 갖게 하려면? : 다른 문자열 데이터를 넣으면 다른 메모리를 부여

	// 문자 포인터의 특성 -> cout은 문자포인터를 특별히 대해준다. 문자열은 데이터를 출력시키고, 숫자형 배열은 시작주소를 출력

	char c = 'Q';
	cout << &c << endl;	// 문자열로 간주 \0이 나올때까지 뽑아낸다



	return 0;
}