/*
	������� �Լ�
*/

#include <iostream>

using namespace std;

class Something
{
public:
	//inner class�� static ������� �ʱ�ȭ
	class _init
	{
	public:
		_init()
		{
			s_value = 9874;
		}
	};

private :
	static int s_value;
	int m_value;

	static _init s_initializer;

public:
	Something()
		: m_value(123)			// �Ұ���! static ��������� ������ �ʱ�ȭ�� �� �� ���� -> �������� ����
	{}

	static int getValue()		// static �Լ��� this�� ������ 
	{
		return s_value;
		//return m_value;		<- �ȵ� ��? ���� �Լ��� ���� ����� ������ ����
	}

	int temp()
	{
		return this->s_value;
	}
};

int Something::s_value = 1024;;
Something::_init Something::s_initializer;

int main()
{ 
	cout << Something::getValue() << endl;

	Something s1,s2;
	cout << s1.getValue() << endl;
	//cout << s1.s_value << endl;

	int (Something::*fptr1)() = &Something::temp;		// class�� �� �Լ��� ��ü���� ������ �ּҸ� ���� ���� �ƴ϶� class�ȿ��� �ϳ��� �ּҸ��� ����

	cout << (s2.*fptr1)() << endl;

	int (*fptr2)() = &Something::getValue;				// static����Լ���? Ư�� �ν��Ͻ��� ������� ���� ��ų�� �ֱ⶧���� �տ� ClassŸ���� ���� �����൵ �ȴ�



	return 0;
}
