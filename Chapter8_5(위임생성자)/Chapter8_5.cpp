/* 
	위임생성자
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

	// 객체 생성시 이름만 넣고 싶을때 -> 위임생성자 C++11 이후
	Student st2("Hera");
	st2.print();

	return 0;
}
