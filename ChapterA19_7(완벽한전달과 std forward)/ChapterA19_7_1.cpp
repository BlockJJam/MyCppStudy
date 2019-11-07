/*
	완벽한 전달을 위해 사용하는 std::forward사용
*/

#include <iostream>
#include <vector>
#include <utility>	// std::forward

using namespace std;

struct MyStruct
{};

void func(MyStruct& s)
{
	cout << "Pass by L-ref" << endl;
}

void func(MyStruct&& s)
{
	cout << "Pass by R-ref" << endl;
}
//
//void func(MyStruct s)
//{
//	cout << "Pass by Value" << endl;
//}

//template<typename T>		// perfect forwarding 안됨!
//void func_wrapper(T t)
//{
//	func(t);
//}

template<typename T>
void func_wrapper(T&& t)
{
	func(std::forward<T>(t));		// 들어온 t가 L-value면 L-value 함수로 보내고, R-value면 R-value함수로 보낸다
}

int main()
{
	MyStruct s;

	func(s);			// l-value	
	func(MyStruct());	// r-value
	// 이 위는 컴파일러가 구분을 해줌, template가 들어가면 컴파일러가 구분 못함

	// perfact forwarding을 해줘서 해결
	func_wrapper(s);
	func_wrapper(MyStruct());



	return 0;
}