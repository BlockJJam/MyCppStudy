
/*
	�����Ϳ� ������ ������� ������( ����ü, Ŭ����)
*/
#include <iostream>

using namespace std;

struct Person
{
	int age;
	double weight;
}
;

int main()
{
	Person person;

	person.age = 5;
	person.weight = 30;
	
	Person &ref_person = person;
	ref_person.age = 15;

	Person *ptr = &person;
	ptr->age = 30;
	(*ptr).age += 20;	// *ptr = &ref_person ���� , �� �Ⱦ�


	Person &ref2_person = *ptr;
	ref2_person.age = 45;

	cout << &person << endl;
	cout << &ref2_person << endl;
	cout << ptr << endl;

	return 0;
}