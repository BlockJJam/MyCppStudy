// 모호성을위해 이걸 써라 하는 것이 Using문, 헤더파일보단 cpp소스파일에 넣자

#include <iostream>
#include <cmath>

using namespace std;

namespace a
{
	int my_var(10);
	int count(123);
}

namespace b
{
	int my_var(20);
}

int main()
{
	using std::cout;
	//using namespace b;		<- 이게 사용되면 밑에 a 네임스페이스에 영향을 줘서 다시 애매해짐
	cout << "hello" << endl;
	{
		using namespace a;
		cout << my_var << endl;
		cout << a::count << endl;
	}
	{
		using namespace b;
		cout << my_var << endl;
	}

	return 0;
}