/* 
	�ڷ��� �ϳ� �������� ���� ���� ǥ���ϱ� ������ ����� ���� �ڷ����������� ������� => struct(����ü)
	�Ű������� ���� �ڷ����� �� ���� �ʿ䵵 ����, ������ �Լ� �ȿ� �� �����ϰ� �ʹ� ����������
*/
#include <iostream>
#include <string>

using namespace std;

struct Person
{
	double height= 123.0;
	float weight = 20.0;
	int age= 12;
	string name= "Mr.Joo";

	// ����ü �ȿ� �α�
	void printPersonInfo()
	{
		cout << height << " " << weight << " " << age << " " << name;
		cout << endl;
	}

};

struct Family
{
	Person me, mom, dad;
};

// �Լ��� struct�� return�� ���� �ִ�
Person getMe()
{
	Person me{ 180.4,40.5,20,"JJM" };
	return me;
}

Person getMom()
{
	Person mom{ 167.4,40.5,20,"KHY" };
	return mom;
}

Person getDad()
{
	Person dad{ 182.4,40.5,20,"JMK" };
	return dad;
}
//����ü �ۿ� �α�
//void printPerson(Person ps)
//{
//	cout << ps.height << " " << ps.weight << " " << ps.age << " " << ps.name;
//	cout << endl;
//}

// ���ݴ� ����� ����
struct Employee										// 2 + (2) + 4 + 8= 14 (16) byte ( id�� 2 -> 4byte�� ������ ) -> padding
{
	short	id;										// 2 byte
	int		age;									// 4 byte
	double	wage;									// 8 byte
};

int main()
{

	Person me;
	me.printPersonInfo();
	// ����� ���������� operator�� �ǵ���� �۵��� �ȵ� �� �ִ� ����! (below)
	Person me2 = getMe();
	me2.printPersonInfo();

	//employee
	Employee emp1;
	
	cout << sizeof(Employee) << endl;				// 14byte (X) -> 16byte (0) �޸𸮱����� �����Ϸ��� ����

	return 0;
}