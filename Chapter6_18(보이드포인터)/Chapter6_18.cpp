/*
	void 포인터( = 제네릭 포인터)
	자료형과 상관없이 포인터를 저장할수도 있을까? 에서 나옴

*/

#include <iostream>

using namespace std;

enum Type
{
	INT,
	FLOAT,
	CHAR,
};

int main()
{
	int i = 5;
	float f = 3.0;
	char c = 'a';

	void *ptr = nullptr;

	ptr = &i;
	//ptr = &f;
	//ptr = &c;

	// 한계는 존재 -> 포인터연산이 안됨
	//cout << ptr + 1 << endl;
	cout << &i << endl;
	cout << ptr << endl;
	cout << *static_cast<int*>(ptr) << endl;

	Type type = FLOAT;		// 과거 void 포인터를 사용해야만 했을 때 type을 설정해주기 위해 사용했던 방식 -> C++최근 문법에는 더 좋은 문법이 나옴
	cout << type << endl;
	if (type == FLOAT);		
	else if (type == INT);

	return 0;
}