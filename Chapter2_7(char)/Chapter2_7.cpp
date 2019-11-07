#include <iostream>

int main()
{
	using namespace std;
	char c1(65);
	char c2('a');
	char c3('c');

	cout << c1 << " " << c2 << " " << int(c1) << " " << int(c2) << endl;

	// c 스타일 - 강제
	cout << (char)65 << endl;
	cout << (int)'A' << endl;


	// C++ 스타일 -강제
	cout << char(65) << endl;
	cout << int('A') << endl;

	// 컴파일에게 변환전에 변화해도 되는지 물어보는 차이?
	cout << static_cast<char>(65) << endl;
	cout << static_cast<int>('A') << endl;   // 객체지향에서는 dynamic_cast가 있다

	cin >> c1;
	cout << c1 << " " << static_cast<int>(c1) << endl;

	cin >> c1;
	cout << c1 << " " << static_cast<int>(c1) << endl;

	cin >> c1;
	cout << c1 << " " << static_cast<int>(c1) << endl;

	cin >> c1;
	cout << c1 << " " << static_cast<int>(c1) << endl;
	// endl 대신 flush는 버퍼에 있는걸 쏟아내라( 줄바꿈 X )

	// 유니코드는 char_32t 같이 더 큰 크기의 char형을 쓴다
	cout << "Hello, \u0444! \n ";

	return 0;
}