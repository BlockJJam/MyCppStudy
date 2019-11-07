#include <iostream>

using namespace std;

class Something
{
public:
	static constexpr int _value = 1;			// constexpr: 컴파일에 무조건 값이 결정되어야한다			
};

//int Something::_value = 1; // staic 멤버의 경우 : define in cpp

int main()
{
	cout << Something::_value << " " << Something::_value << endl;

	Something st1;
	Something st2;

	//st1._value=2;

	cout << &st1._value << " " << st1._value << endl;
	cout << &st2._value << " " << st2._value << endl;

	//Something::_value = 1024;

	cout << &Something::_value << " " << Something::_value << endl;

	return 0;
}
