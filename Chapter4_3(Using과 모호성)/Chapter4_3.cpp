// ��ȣ�������� �̰� ��� �ϴ� ���� Using��, ������Ϻ��� cpp�ҽ����Ͽ� ����

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
	//using namespace b;		<- �̰� ���Ǹ� �ؿ� a ���ӽ����̽��� ������ �༭ �ٽ� �ָ�����
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