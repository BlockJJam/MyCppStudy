// 같은 이름의 함수를 사용해야 할 때 nmaespace를 사용 ( :: 사용)

#include <iostream>

using namespace std;

namespace MySpace1
{
	namespace InnerSpace
	{
		int myFunction()
		{
			return 0;
		}
	}
	int doSomething(int a, int b)
	{
		return a + b;
	}
}

namespace MySpace2
{
	int doSomething(int a, int b)
	{
		return a * b;
	}
}

int main()
{
	using namespace MySpace1;
	using namespace MySpace1::InnerSpace;

	cout << doSomething(1, 2) << endl;
	cout << MySpace2::doSomething(1, 2) << endl;
	cout << MySpace1::InnerSpace::myFunction() << endl;


	return 0;
}