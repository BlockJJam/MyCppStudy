/*
	�Ҹ��� destructor(�ı��� �ǹ̴� �ƴ�)
		-> ���� ������? delete �� �� ,�Ҹ��ڿ� delete�� �־ �ش� array�� ������ ȣ���� �� �Ҹ��ڰ� ȣ��Ǹ鼭 �޸� ������ ���� �� �ִ�
		-> vector ���ο� �Ҹ��ڿ� �̹� delete�� �ִ�
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

	//�Ҹ���
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
	Simple *s1 = new Simple(0);		// �����Ҵ��� delete�� �޸𸮸� ������ �� �Ҹ��ڰ� ���� 
	Simple s2(1);

	delete s1;

	while (true)
	{
		IntArray my_int_arr(10000);
	}

	return 0;
}
