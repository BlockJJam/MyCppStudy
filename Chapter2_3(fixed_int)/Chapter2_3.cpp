#include <iostream>
//#include <cstdint>

int main()
{
	using namespace std;
	
	std::int16_t i(5);
	std::int8_t myint = 65;  // char임, 안쓰는게 낫다

	cout << myint << endl;

	std::int_fast8_t fi(5);				// fast : 8비트 중에 제일 빠른 타입 => 8비트면 signed char
	std::int_least64_t fl(5);			// least : 적어도 64비트를 갖는 타입



}