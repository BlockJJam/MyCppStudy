/*
	현대적 프로그래밍에서 코드의 유연함을 가져다 주는 lambda함수, std::function, std::bind, for_each

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
		[&]() {cout <<"3 " << name << endl; }();		// [&] <-밖에 있는 멤버를 참조로 가져온다, [=] <- 복사, [this] <- class 멤버
	}

	vector<int> v;
	v.push_back(1);
	v.push_back(2);

	auto func2 = [](int val) { cout <<"4 "<< val << endl; };
	for_each(v.begin(), v.end(), [](int val) { cout <<"5 " << val << endl; });

	cout << "6" << []()-> int { return 1; } () << endl;

	// function 포인터를 체계화 시켜줌
	function<void(int)> func3 = func2;
	
	func3(123);

	// bind를 써서 아예 아래예에서 처럼 456으로 파라미터를 넣어서 바인드한다
	function<void()> func4 = bind(func3, 456);
	func4();

	// PlaceHolder :
	// https://en.cppreference.com/w/cpp/utility/functional/placeholders
	{
		Object instance;
		auto f = bind(&Object::hello, &instance, placeholders::_1);		// parameter가 여러개 들어가야 할 때 사용, Object 클래스의 함수가 쓰이는데 객체가 필요하므로 &instance가 필요
		f(",JJM");		// 이 파라미터 placeholder가 맡아놓은 매개변수 자리에 들어감

		auto f2 = bind(&goobye, placeholders::_1);		
		f2("JJM");
	}
	return 0;
}