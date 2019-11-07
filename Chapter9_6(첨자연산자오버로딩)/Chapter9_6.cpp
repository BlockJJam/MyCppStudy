/*
	[] ÷�� ������ �����ε� �ϱ�
		-> assert�� ���� �͵� ����
		-> �迭 ÷�� ���� ����~

	
	
	
	// ÷�� �����ε� X�϶�

public:
	void setItem(int index, int value)
	{
		_list[index] = value;
	}

	int getItem(int index)
	{
		return _list[index];
	}

	// array ��ü�� �����ͷ� return�ϴ� ���
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
		assert(index >= 0);								// if���� ����ϸ� ��������
		assert(index < 10);

		return _list[index];
	}

	const int & operator [] (const int index) const		// �ڿ� const�� �ٴ� �� : �� ����� ���� �ٲ��� �ʰڴ�
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

	// () ��ȣ�� ���ֱ� ���� ÷�� ������ �����ε�
	my_list[3] = 10;
	cout << my_list[3] << endl;

	const IntList my_list2;
	my_list2[3];
	cout << my_list2[1] << endl;

	// �����͸� �� ��
	IntList *list = new IntList;

	(*list)[3] = 10;


	return 0;
}