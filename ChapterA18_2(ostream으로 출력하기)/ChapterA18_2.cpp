/*
	ostream으로 출력하기
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout.setf(ios::showpos);			// setf() : 출력옵션 설정
	cout << 108 << endl;

	cout.unsetf(ios::showpos);			// setf() : 설정 해제
	cout << 109 << endl;

	//cout.unsetf(ios::dec);
	cout.setf(ios::hex, ios::basefield);
	cout << 108 << endl;

	//cout.setf(std::ios::uppercase);
	cout << std::hex << std::uppercase;
	cout << 108 << endl;
	cout << 109 << endl;

	cout << std::dec;
	cout << 108 << endl;

	cout << std::boolalpha;
	cout << true << " " << false << endl;

	//cout << std::defaultfloat;
	//cout << std::fixed;									// 숫자가 없는자리수 소수점 0으로 고정
	//cout << std::scientific;								// 소수점을 e+.. 로 만들기
	cout << std::showpoint;									// .을 보이게
	cout << std::setprecision(3) << 123.456 << endl;
	cout << std::setprecision(4) << 123.456 << endl;
	cout << std::setprecision(5) << 123.456 << endl;
	cout << std::setprecision(6) << 123.456 << endl;
	cout << std::setprecision(7) << 123.456 << endl;

	cout << -12345 << endl;
	cout.fill('*');												// 빈칸을 * 로 채우기
	cout << std::setw(10) << -12345 << endl;					// 10칸 채우고 -12345
	cout << std::setw(10) << std::left << -12345 << endl;		// 왼쪽으로 붙고
	cout << std::setw(10) << std::right << -12345 << endl;		// 오른쪽으로 붙고
	cout << std::setw(10) << std::internal << -12345 << endl;	// 부호를 떼어놓는다



	return 0;
}