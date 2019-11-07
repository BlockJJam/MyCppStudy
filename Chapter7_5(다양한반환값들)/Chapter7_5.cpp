#include <iostream>
#include <array>
#include <tuple>
using namespace std;

int getValue(int x)
{
	int value = x * 2;
	return value;
}

int* getValue2(int x)
{
	int value = x * 2;
	return &value;
}

int* allocateMemory(int size)
{
	return new int[size];
}

int& getValue3(int x)
{
	int value = x * 2;
	return value;
}

int& getElement(array<int, 100>& my_array, int ix)
{
	return my_array[ix];
}

struct S
{
	int a, b, c, d;
};

S getStruct()
{
	S my_s{ 1,2,3,4 };
	return my_s;
}

tuple<int, double,double> getTuple()
{
	int a = 10;
	double d = 3.14;
	double b = 3.3;
	return make_tuple(a, d, b);
}

int main()
{
	int value = getValue(3);

	//주소값으로 돌려받기
	int value2 = *getValue2(3);				//사라질 변수에 대한 de-ref한다는게 에러를 유발가능성 있음 *value = getValue(3); 은 더 위험

	cout << value2 << endl;

	//동적배열 할당 new를 빼서 사용하고 싶을 때
	int *my_array = allocateMemory(1024);
	
	delete[] my_array;

	// 참조변수 반환
	int &value3 = getValue3(5);

	cout << value3 << endl;
	cout << value3 << endl;					// 참조변수가 사용되고 사라지기 때문에 쓰레기값이 들어감

	array<int, 100> my_arr;
	my_arr[30] = 10;

	getElement(my_arr, 30) *= 10;
	cout << my_arr[30] << endl;

	// 여러개 리턴
	S my_s = getStruct();
	my_s.b;										// 1) 구조체 ->이러면 구현 오버헤드다

	tuple<int, double,double> my_tp = getTuple();		// 2) 튜플 -> 아직도 조금 불편
	cout << get<0>(my_tp) << " ";
	cout << get<1>(my_tp) << endl;

	auto[a, b,c] = getTuple();					// 3) C++17스타일
	cout << a << endl;
	cout << b << endl;

	return 0;
}