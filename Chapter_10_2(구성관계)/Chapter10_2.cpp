/*
	 ���� ����
	 ���� - Monster Ŭ����

		��ü/��ǰ ����
		�ٸ� Ŭ������ ���� �� �ִ°�?			No
		����� ���縦 Ŭ������ �����ϴ°�?		Yes
		�ܹ���
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