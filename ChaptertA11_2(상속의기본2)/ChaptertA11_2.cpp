/*
	상속의 기본 2
		-> 문법을 했으니, 사례를 가지고 어떤 경우에 쓰는지
*/

#include "Teacher.h"
#include "Student.h"
using namespace std;

int main()
{
	Student std("Jack Jack");
	Teacher teacher("Prof. hong");

	std.setName("Jack 2222");
	std.getName();
	cout << std.getName() << endl;

	teacher.setName("Dr. hong");
	cout << teacher.getName() << endl;

	cout << std << endl;
	cout << teacher << endl;

	std.doNothing();
	teacher.doNothing();
	
	std.study();
	teacher.teach();

	Person person;
	person.setName("Mr. Incredible");
	person.getName();
	//person.study();	// error
	//person.teach(); // error

	return 0;
}