/* 
	���ӻ�����
*/

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	int		_id;
	string	_name;

public:

	Student(const string& name_in)
		: Student(0, name_in)
	{}

	Student(const int &id_in, const string& name_in)
		: _id(id_in), _name(name_in)
	{}

	void print()
	{
		cout << _id << " " << _name << endl;
	}
};

int main()
{
	Student st1(0, "Jack jack");
	st1.print();

	// ��ü ������ �̸��� �ְ� ������ -> ���ӻ����� C++11 ����
	Student st2("Hera");
	st2.print();

	return 0;
}
