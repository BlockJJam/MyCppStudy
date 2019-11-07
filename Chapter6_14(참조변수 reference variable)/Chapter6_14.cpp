/*
	참조 변수

	1) 참조는 별명으로 사용될 수 있다
	2) 별명이 있어야 하니까 초기화 필수
	3) 피연산자로 변수가 들어가야 한다

	요즘 추세는 매개변수 값을 못바꾸게 하는 것이 추세 -> 매개변수를 const로
	입력은 순수하게 입력만(수정없이), 반환은 여러개로 받아도 된다
*/

#include <iostream>

using namespace std;

void doSomething(const int &n)
{
	//n = 10;
	cout << &n << endl;							// 포인터로 매개변수로 넘기면 주소가 다른데 반해(복사), 참조변수는 매개변수로 넘기면 변수자체 메모리가 넘어감(참조(효율))
	cout << " In doSomething " << n << endl;		
}

void printElements(int(&arr)[5])
{
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st;
};


int main()
{
	int value = 5;
	
	//포인터
	int *ptr = nullptr;
	ptr = &value;

	//참조
	int &ref = value;		// value가 갖는 메모리를 참조
	
	cout << ref << endl;

	ref = 10;	// *ptr =10;

	cout << value << " " << ref << endl;

	cout << &value << endl;
	cout << &ref << endl;
	cout << ptr << endl;
	cout << &ptr << endl;

	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	int x = 5;
	int &ref_x = x;
	const int y = 8;	
	const int &ref_y = y;		// const를 참조할때는 reference도 const로

	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	// reasign

	int value1 = 5;
	int value2 = 10;
	int &ref3 = value1;

	cout << ref3 << endl;
	ref3 = value2;
	cout << ref3 << endl;
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	// 매개변수로 참조변수를 넘겨줄때

	int n = 5;
	cout << n << endl;
	cout << &n << endl;

	doSomething(n);

	cout << n << endl;

	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	
	// arr를 참조변수로 매개변수로 넘길때
	const int length = 5;
	int arr[length] = { 1,2,3,4,5 };

	printElements(arr);

	// 구조체
	Other ot;
	ot.st.v1 = 1.0;		// 불편 더럽

	int  &v1 = ot.st.v1;	// 참조 변수 사용
	v1 = 1;

	// 참조변수와 포인터 비교
	int value3 = 5;
	int value4 = 6;
	int *const ptr2 = &value3;	// 주소 못바꿈
	int &ref4 = value3;

	// ptr2 = &value4;
	ref4 = value4;
	cout << "ref4 :" << &ref4 << endl;
	cout << "value3 : " << &value3 << endl;
	return 0;
}