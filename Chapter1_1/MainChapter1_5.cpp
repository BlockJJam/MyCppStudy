#include <iostream>
/*

< �Լ��� ���� >

C++�� �Լ� �ȿ��� �Լ��� ���ǰ� �ȵ� ( ���̽�, �ڹٽ�ũ��Ʈ�� ���� )

int a()
{
	int b()
	{

	}
}


*/
using namespace std;

int multiTwoNumbers(int num_a, int num_b)
{
	int sum = num_a * num_b;

	return sum;
}

void printHelloWorld()
{
	cout << "hello World! " << endl;

	return;
}
int main()
{
	int sum = multiTwoNumbers(1, 2);
	cout << multiTwoNumbers(1, 2) << endl;
	cout << multiTwoNumbers(1, 3) << endl;
	cout << multiTwoNumbers(1, 4) << endl;

	printHelloWorld();
	return 0;
}