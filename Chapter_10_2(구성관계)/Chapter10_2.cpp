/*
	 구성 관계
	 예시 - Monster 클래스

		전체/부품 관계
		다른 클래스에 속할 수 있는가?			No
		멤버의 존재를 클래스가 관리하는가?		Yes
		단방향
*/

#include <iostream>
#include "Monster.h"

using namespace std;

int main()
{
	Monster mon1("Sanson", Position2D(0,0));
	mon1._location;
	cout << mon1 << endl;

	Monster mon2("Partial", Position2D(0, 0));
	mon2._location;

	//while (1)		// game loop
	{
		// event
		mon1.moveTo(Position2D(1,1));
		cout << mon1 << endl;
	}
	return 0;
}