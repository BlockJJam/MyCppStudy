#include <iostream>
//#include <cstdint>

int main()
{
	using namespace std;
	
	std::int16_t i(5);
	std::int8_t myint = 65;  // char��, �Ⱦ��°� ����

	cout << myint << endl;

	std::int_fast8_t fi(5);				// fast : 8��Ʈ �߿� ���� ���� Ÿ�� => 8��Ʈ�� signed char
	std::int_least64_t fl(5);			// least : ��� 64��Ʈ�� ���� Ÿ��



}