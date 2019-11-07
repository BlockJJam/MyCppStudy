/*

<지역범위>

밑의 x의 선언이 3번 이루어졌는데 ( int x=1, x=2, x(0) )
 -> 각각의 영역이 {}를 써서 다르기 때문에 가능하다
 cout을 써서 x의 메모리 주소를 확인해보자

 => 즉, 지역변수는 영역을 벗어났을 때 사용할 수 없게 된다 


*/

#include <iostream>
using namespace std;

int main()
{
	int x(0); //객체지향에서 가능한 표현 x=0 ; x가 인스턴스를 갖는다
	{
		//영역 boundary표현
		int x = 1;
		cout << x << " " << &x << endl;
	}

	{
		int x = 2;
		cout << x << " " << &x << endl;
	}

	
	cout << x << " " << &x << endl;

	return 0;
}