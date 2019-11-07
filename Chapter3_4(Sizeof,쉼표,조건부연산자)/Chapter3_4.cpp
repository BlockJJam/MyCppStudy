/*
	sizeof는 내가 만든 데이터 타입의 크기도 알 수 있다
		변수 명은 ()없이도 쓸 수 있다 -> int a; sizeof a;

	,(쉼표) 연산자는 앞의 연산을 하고 쭉 나가서 마지막 콤마 뒤의 값이 들어간다
		int z  = (++x, ++y); -> ++x; ++y; int z=y;
		,연산이 아닌 데에서는 구분기호로만 쓰임
	


*/


#include <iostream>
#include <cmath>

using namespace std;

int getPrice(bool onSale)
{
	if (onSale) return 10;
	else return 100;
}
int main()
{

	// conditional operator (arithmetric if)
	bool onSale = true;

	//const int price = (onSale == true) ? 10 : 100;	// <- 간단한 조건부에선 삼항연산자가 유리
	const int price = getPrice(onSale);					// <- 좀 더 복잡한 조건부에선 함수로 빼는게 유리
	
	int x = 5;
	cout << ((x % 2 == 0) ? "even" : "odd") << endl;
	return 0;
}