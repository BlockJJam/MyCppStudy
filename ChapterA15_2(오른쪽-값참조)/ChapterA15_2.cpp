/*
	������ �� ����
		-> move semantics �� ����ص� �Ǵ� �� �Ǵ��ϱ� ����
		-> L-value : �ٸ� ��𼱰� ����Ϸ��� ���� �� �� �ֵ��� �ֵ� ( int x )
		-> R-value : �ӽ÷� ����Ϸ��� ����	( 5 )
		-> ( const int &&rr1 = 5; ) => R-value reference : &&rr , R-value : 5

		��, ������ �� ������ ���� r-value�� ������ rr1�� ������ �� �ְ�, ���� �ٲ� �� �־��� �ǹ�
*/

#include <iostream>
using namespace std;

void doSomething(int &lref)
{
	cout << "L-value ref" << endl;
}

// L value�� R value�� �����ε� ����
void doSomething(int &&ref)				// �޸𸮿� ��� ����ǰ� �� �ֵ��� R-value ref�� �޾Ƽ� ó�������ϴ� 
{
	cout << "R-value ref" << endl;
}

int getResult()
{
	return 5;
}


int main()
{
	int x = 5;
	int y = getResult();
	const int cx = 6;
	const int cy = getResult();

	// L-value reference

	int &lr1 = x;			// Modifiable l-values
	//int &lr2 = cx;		// Non-modifiable l-values
	//int &lr3 = 5;			// R-values	<- �߿�

	const int &lr4 = x;		// Modifiable l-values
	const int &lr5 = cx;	// Non-modifiable l-values
	const int &lr6 = 5;		// R-values	<- �߿�

	// R - value reference

	//int &&rr1 = x;
	//int &&rr2 = cx;
	int &&rr3 = 5;				// R-value �� ���� �� ���� -> �ӽ������ �ָ� �޸𸮿� ���� 
	int &&rr7 = getResult();	// �� ����� �ֵ鸸 ���� �� ����

	cout << rr3 << endl;
	rr3 = 10;
	cout << rr3 << endl;

	// const int &&rr4 =x;
	// const int &&rr5 = cx;
	const int &&rr6 = 5;

	doSomething(x);
	doSomething(5);
	doSomething(getResult());

	return 0;
}