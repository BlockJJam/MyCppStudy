/*
	클래스 템플릿 특수화 specialization ( 내 생각엔 부분화라고 보는게 맞다 )
*/

#include <iostream>
#include <string>
#include "Storage8.h"
using namespace std;

//template <typename T>
//class A
//{
//public:
//	//생성자로 <int> 와 같은 선언을 피하도록
//	A(const T& input)
//	{}
//
//	void doSomething()
//	{
//		cout << typeid(T).name() << endl;
//	}
//	void test()
//	{}
//};
//
//template<>
//class A<char>
//{
//public:
//	A(const char &temp)
//	{}
//
//	void doSomething()
//	{
//		cout << "Char Type specialization" << endl;
//	}
//};

int main()
{
	//A a_int(1);						// C++ 17에서는 <type>을 빼도 되고 넣어도 된다( A<int> a_int(1); )	
	//A a_double(3.14);				// ( A<double> a_double(1); )
	//A a_char('a');					// ( A<char> a_char(1); )

	//a_int.doSomething();
	//a_double.doSomething();
	//a_char.doSomething();

	//a_int.test();
	//a_double.test();
	// a_char.test(); 안됨

	Storage8 <int> intStorage;
	for (int count = 0; count < 8; count++)
		intStorage.set(count, count);
	
	for (int count = 0; count < 8; count++)
		std::cout << intStorage.get(count) << '\n';

	cout << "size Storage8<int> " << sizeof(Storage8<int>) << endl;

	Storage8 <bool> boolStroage;
	for (int count = 0; count < 8; count++)
		boolStroage.set(count, count&3);

	for (int count = 0; count < 8; count++)
		std::cout << (boolStroage.get(count)? "true" : "false") << '\n';

	cout << "size Storage8<bool> " << sizeof(Storage8<bool>) << endl;


	return 0;
}