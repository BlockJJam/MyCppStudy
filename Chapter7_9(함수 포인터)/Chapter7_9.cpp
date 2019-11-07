/*
	�Լ� ������
		-> �Լ��� �����ʹ�( �޸��ּҰ� �ִ�)

*/
#include <iostream>
#include <array>
#include <functional>		// c++ 17 �� ���� �Լ������� ����

using namespace std;

int func(int x)
{
	return 5;
}

int goo(int x)
{
	return 10;
}

bool isEven(const int &number)
{
	if (number % 2 == 0) return true;

}

bool isOdd(const int &number)
{
	if (number % 2 == 1) return true;

}

// �Լ� �����Ͱ� ����ϰ� ���ȴٸ� typedef�� ���°� ����
//typedef bool(*check_fcn_t)(const int&);
using check_fcn_t = bool(*)(const int&);

void printNumbers(const array<int, 10> &my_array, function<bool(const int&)> check_fcn)	// array����, �Լ�������
{
	for (auto element : my_array)
	{
		if(check_fcn(element) ==true)cout << element;
		//if (!print_even && element % 2 == 1) cout << element;
	}
	cout << endl;
}



int main()
{
	// �Լ������� ����
	int(*fcnptr)(int) = func;
	
	cout << fcnptr(1) << endl;

	fcnptr = goo;

	cout << fcnptr(2) << endl;
	
	
	array<int, 10> my_array{ 0,1,2,3,4,5,6,7,8,9 };

	printNumbers(my_array, isEven);
	printNumbers(my_array, isOdd);

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	// functional lib ���
	function<bool(const int&)> fcnptr2 = isEven;

	printNumbers(my_array, fcnptr2);

	fcnptr2 = isOdd;

	printNumbers(my_array, fcnptr2);

	return 0;
}