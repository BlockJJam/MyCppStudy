/*
	���� ������ �����ε�
	�������� vs ��������
		-> vector�� string�� ���� ���̺귯���� ������ ���� ������ �̷� ����� �� �ʿ� ���� ����
		-> �˰� �־��, �̷� ������ �����ϱ� 

	��������
	: ������ ������ �ּҰ��� �������ִ� ��

	��������
	: �޸𸮸� ���� �Ҵ� �޾� ������ �����ϴ� ��
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

		_length = std::strlen(source) + 1;		// \0�� �߰��ϱ� ���� 
		_data = new char[_length];

		for (int i = 0; i < _length; i++)
			_data[i] = source[i];

		_data[_length - 1] = '\0';
	}

	// ��������ڸ� ����� ���ſ� ���� �׳� delete�� ���ƹ����� �͵� �ϳ��� ���
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

		if (this == &source)	// prevent self-assignment ( �ڱ��ڽ��Ҵ� ���� )
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
	//	MyString copy = hello;					// ���� ������ ȣ��( hello�ּҸ� �ޱ⸸ ���� ������ ���� ����) -> �Ҹ��ڰ� _data �� delete��
	//	cout << (int*)copy._data << endl;
	//	cout << copy.getString() << endl;
	//}											// ���⼭ ����� ����� �Ҹ�~! hello��_data�� delete��
	//
	//cout << hello.getString() << endl;			// �̻��� ���� ����	-> release������ copy���� �����Ƿ� �ȳ��ư�

	MyString str1(hello);						// MyString str1 = hello;	
	MyString str2;
	str2 = hello;
	return 0;
}