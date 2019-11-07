
#include <iostream>
#include <cmath>

using namespace std;

auto add(int x, int y) -> int			// 매개변수로는 auto를 쓰지 못하지만 (template을 쓰면 편하다 뒤에 배)
{										// "-> int" 는 트레일링으로 return 타입지정 보기편함
	return x + (double)y;
}
int main()
{
	auto a = 123;
	auto b = 123.0;
	auto c = 1 + 2.0;
	auto d = 'A';
	auto e = "hello";

	auto result = add(1 ,2);

	cout << a << " " << b << " " << c << " " << d << " " << e << " " << endl;
	cout << result << endl;
	return 0;
}