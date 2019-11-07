/*
	std::initializer_list( array를 클래스 같은 사용자 정의 자료형에서 생성자나 대입연사자를 만들 때 편하게 사용가능) 
*/

#include <iostream>
#include <initializer_list>
#include <cassert>
using namespace std;

class IntArray
{
private:
	unsigned _length = 0;
	int *_data = nullptr;

public:
	IntArray(unsigned length)
		:_length(length)
	{
		_data = new int[length];
	}

	IntArray(const initializer_list<int> &list)
		: IntArray(list.size())
	{
		int count = 0;
		for (auto & element : list)
		{
			_data[count] = element;
			++count;
		}
	}

	~IntArray()
	{
		delete[] this->_data;
	}

	//TODO: overload operator = 

	friend ostream & operator << (ostream & out, IntArray & arr)
	{
		for (unsigned i = 0; i < arr._length; i++)
			out << arr._data[i] << " ";
		out << endl;

		return out;
	}
};

int main()
{
	int my_arr1[5] = { 1,2,3,4,5 };
	int *my_arr2 = new int[5]{ 1,2,3,4,5 };

	auto il = { 20,30,40 };							// initializer_list

	IntArray int_array{1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << int_array << endl;
	
	return 0;
}