/*
	std::move
		-> 컴파일러의 결정이 아닌 프로그래머 스스로 move semantics를 사용하고 싶을 때
*/

#include "AutoPtr.h"
#include "Resource.h"
#include <vector>
#include <string>

using namespace std;

template<class T>
void MySwap(T &a, T &b)
{
	// copy semantics
	/*T tmp = a;
	a = b;
	b = tmp;*/
	
	// move semantics
	T tmp{ std::move(a) };
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{
	//{
	//	AutoPtr<Resource> res1(new Resource(10000000));

	//	cout << res1._ptr << endl;

	//	AutoPtr<Resource> res2 = std::move(res1);			// copy와 move 가 있는데 move semantics를 사용하고 싶다 -> std::move

	//	cout << res1._ptr << endl;
	//	cout << res2._ptr << endl;
	//}

	/*{
		AutoPtr<Resource> res1(new Resource(3));
		res1->setAll(3);

		AutoPtr<Resource> res2(new Resource(5));
		res2->setAll(5);

		cout << endl;

		res1->print();
		res2->print();

		MySwap(res1, res2);

		cout << endl;

		res1->print();
		res2->print();
	}*/

	//{
	//	vector <string> v;
	//	string str = "hello";
	//	v.push_back(str);					//copy

	//	cout << str << endl;
	//	cout << v[0] << endl;

	//	v.push_back(std::move(str));		// move

	//	cout << str << endl;				// str이 v[1]로 move가 됨
	//	cout << v[0] << " " << v[1] << endl;

	//}

	{
		string x{ "abc" };
		string y{ "de" };

		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
		
		MySwap(x, y);

		cout << "x: " << x << endl;
		cout << "y: " << y << endl;
	}


	return 0;
}