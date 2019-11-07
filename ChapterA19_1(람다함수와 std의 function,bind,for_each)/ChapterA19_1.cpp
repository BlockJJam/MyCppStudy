/*
	������ ���α׷��ֿ��� �ڵ��� �������� ������ �ִ� lambda�Լ�, std::function, std::bind, for_each

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Object
{
public:
	void hello(const string & s)
	{
		cout << "7 hello" << s << endl;
	}

};

void goobye(const string &s)
{
	cout << "8 Good bye " << s << endl;
}

int main()
{
	// lambda-introducer				[]
	// lambda-parameter-declaration		(const int &i)
	// lambda-return-type-clause		void
	// compaund-statement				{ cout << "Hello,world!" << endl; };
	auto func = [](const int &i) -> void { cout << "1" <<"Hello,world!" << endl; };

	func(123);

	[](const int &i) -> void { cout << "2 Hello,world!" << endl; }(1234);

	{
		string name = "JackJack";
		[&]() {cout <<"3 " << name << endl; }();		// [&] <-�ۿ� �ִ� ����� ������ �����´�, [=] <- ����, [this] <- class ���
	}

	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	auto func2 = [](int val) { cout <<"4 "<< val << endl; };
	for_each(v.begin(), v.end(), [](int val) { cout <<"5 " << val << endl; });

	cout << "6" << []()-> int { return 1; } () << endl;

	// function �����͸� ü��ȭ ������
	function<void(int)> func3 = func2;
	
	func3(123);

	// bind�� �Ἥ �ƿ� �Ʒ������� ó�� 456���� �Ķ���͸� �־ ���ε��Ѵ�
	function<void()> func4 = bind(func3, 456);
	func4();

	// PlaceHolder :
	// https://en.cppreference.com/w/cpp/utility/functional/placeholders
	{
		Object instance;
		auto f = bind(&Object::hello, &instance, placeholders::_1);		// parameter�� ������ ���� �� �� ���, Object Ŭ������ �Լ��� ���̴µ� ��ü�� �ʿ��ϹǷ� &instance�� �ʿ�
		f(",JJM");		// �� �Ķ���� placeholder�� �þƳ��� �Ű����� �ڸ��� ��

		auto f2 = bind(&goobye, placeholders::_1);		
		f2("JJM");
	}
	return 0;
}