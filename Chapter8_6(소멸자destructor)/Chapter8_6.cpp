/*
	소멸자 destructor(파괴의 의미는 아님)
		-> 언제 쓰나요? delete 할 때 ,소멸자에 delete를 넣어서 해당 array를 무한히 호출할 때 소멸자가 호출되면서 메모리 누수를 피할 수 있다
		-> vector 내부에 소멸자에 이미 delete가 있다
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Simple
{
private:
	int _id;

public:
	Simple(const int& id_in)
		: _id(id_in)
	{
		cout << "Constructor " << _id << endl;
	}

	//소멸자
	~Simple()
	{
		cout << "Destructor " << _id << endl;
	}
};

class IntArray
{
private :
	int *_arr = nullptr;
	int _length = 0;

public :
	IntArray(const int length_in)
	{
		_length = length_in;
		_arr = new int[_length];

		//cout << "Constructor" << endl;
	}

	~IntArray()
	{
		if(_arr != nullptr)
			delete[] _arr;
	}

	int size()
	{
		return _length;
	}
};

int main()
{
	//Simple s1(0);
	Simple *s1 = new Simple(0);		// 동적할당은 delete로 메모리를 해제할 때 소멸자가 생성 
	Simple s2(1);

	delete s1;

	while (true)
	{
		IntArray my_int_arr(10000);
	}

	return 0;
}
