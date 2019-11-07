
/*
	포인터와 참조의 멤버선택 연산자( 구조체, 클래스)
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
	(*ptr).age += 20;	// *ptr = &ref_person 같음 , 잘 안씀


	Person &ref2_person = *ptr;
	ref2_person.age = 45;

	cout << &person << endl;
	cout << &ref2_person << endl;
	cout << ptr << endl;

	return 0;
}