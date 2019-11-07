/*
	대입 연산자 오버로딩
	깊은복사 vs 얕은복사
		-> vector나 string과 같은 라이브러리를 가져다 쓰기 때문에 이런 고민은 할 필요 거의 없음
		-> 알고만 있어라, 이런 문제도 있으니까 

	얕은복사
	: 포인터 조차도 주소값만 복사해주는 것

	깊은복사
	: 메모리를 새로 할당 받아 내용을 복사하는 것
*/

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class MyString
{
private:
public:
	char * _data = nullptr;
	int _length = 0;

public:
	MyString(const char *source = "")
	{
		assert(source);

		_length = std::strlen(source) + 1;		// \0을 추가하기 위해 
		_data = new char[_length];

		for (int i = 0; i < _length; i++)
			_data[i] = source[i];

		_data[_length - 1] = '\0';
	}

	// 복사생성자를 만들기 버거울 때는 그냥 delete로 막아버리는 것도 하나의 방법
	// MyString(const MyString &source) = delete;

	MyString(const MyString &source)			// copy constructor
	{
		cout << "Copy constructor " << endl;

		_length = source._length;
		if (source._data != nullptr)
		{
			_data = new char[_length];

			for (int i = 0; i < _length; i++)
				_data[i] = source._data[i];
		}
		else
			_data = nullptr;
	}

	MyString & operator = (const MyString &source)
	{
		cout << "Assignment operator" << endl;

		if (this == &source)	// prevent self-assignment ( 자기자신할당 통제 )
			return *this;
		
		delete[] _data;

		_length = source._length;
		
		if (source._data != nullptr)
		{
			_data = new char[_length];

			for (int i = 0; i < _length; i++)
				_data[i] = source._data[i];
		}
		else
			_data = nullptr;
	}

	~MyString()
	{
		delete[] _data;
		cout << "destructor called" << endl;
	}

	char* getString()
	{
		return _data;
	}

	int getLength() 
	{
		return _length; 
	}
};

int main()
{
	MyString hello("Hello");

	//cout << (int*)hello._data << endl;
	//cout << hello.getString() << endl;

	//{
	//	MyString copy = hello;					// 복사 생성자 호출( hello주소를 받기만 했지 생성을 하진 않음) -> 소멸자가 _data 를 delete함
	//	cout << (int*)copy._data << endl;
	//	cout << copy.getString() << endl;
	//}											// 여기서 블록을 벗어나며 소멸~! hello의_data가 delete됨
	//
	//cout << hello.getString() << endl;			// 이상한 글자 나옴	-> release에서는 copy하지 않으므로 안날아감

	MyString str1(hello);						// MyString str1 = hello;	
	MyString str2;
	str2 = hello;
	return 0;
}