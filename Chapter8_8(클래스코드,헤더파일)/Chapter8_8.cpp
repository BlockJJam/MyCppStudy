/*
	Ŭ���� �ڵ�, �������
*/

#include "Calc.h"

using namespace std;


int main()
{
	// Chaining member fucntions
	Calc cal(10);
	cal.add(10).sub(10).mul(10).print();

	return 0;
}
