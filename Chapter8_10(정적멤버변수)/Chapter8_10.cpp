#include <iostream>

using namespace std;

class Something
{
public:
	static constexpr int _value = 1;			// constexpr: �����Ͽ� ������ ���� �����Ǿ���Ѵ�			
};

//int Something::_value = 1; // staic ����� ��� : define in cpp

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
