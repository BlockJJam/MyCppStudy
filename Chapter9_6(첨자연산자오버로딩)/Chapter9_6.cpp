/*
	[] 첨자 연산자 오버로딩 하기
		-> assert를 쓰는 것도 좋다
		-> 배열 첨자 관련 느낌~

	
	
	
	// 첨자 오버로딩 X일때

public:
	void setItem(int index, int value)
	{
		_list[index] = value;
	}

	int getItem(int index)
	{
		return _list[index];
	}

	// array 자체를 포인터로 return하는 방식
	int * getList()
	{
		return _list;
	}
*/

#include <iostream>
#include <cassert>

using namespace std;

class IntList
{
private:
	int _list[10] = { 0, };

public:
	int & operator [] (const int index)
	{
		assert(index >= 0);								// if문은 사용하면 성능저하
		assert(index < 10);

		return _list[index];
	}

	const int & operator [] (const int index) const		// 뒤에 const가 붙는 것 : 이 멤버의 값을 바꾸지 않겠다
	{
		return _list[index];
	}
};

int main()
{
	IntList my_list;
	/*my_list.setItem(3, 1);
	cout << my_list.getItem(3) << endl;
	my_list.getList()[3] = 1;
	cout << my_list.getList()[3] << endl;*/

	// () 괄호를 빼주기 위해 첨자 연산자 오버로딩
	my_list[3] = 10;
	cout << my_list[3] << endl;

	const IntList my_list2;
	my_list2[3];
	cout << my_list2[1] << endl;

	// 포인터를 쓸 때
	IntList *list = new IntList;

	(*list)[3] = 10;


	return 0;
}