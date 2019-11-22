/*
	집합관계
	예시 - 학교 수업의 학생과 선생

		전체/부품 관계
		다른 클래스에 속할 수 있는가?			Yes
		멤버의 존재를 클래스가 관리하는가?		No
		단방향
*/

#include <iostream>
#include <vector>
#include <string>
#include "Lecture.h"

using namespace std;

int main()
{
	using namespace std;

	Student *std1 = new Student("Jack Jack", 0);
	Student *std2 = new Student("Dash", 0);
	Student *std3 = new Student("Violet", 0);

	Teacher *teacher1 = new Teacher("Prof. Hong");
	Teacher *teacher2 = new Teacher("Prof. Good");

	Lecture lec1("Introduction to Computer Programming");
	lec1.assignTeacher(teacher1);
	lec1.registerStudent(std1);
	lec1.registerStudent(std2);
	lec1.registerStudent(std3);

	Lecture lec2("Computational Thinking");
	lec2.assignTeacher(teacher2);
	lec2.registerStudent(std1);

	{
		cout << lec1 << endl;
		cout << lec2 << endl;

		lec2.study();

		cout << lec1 << endl;
		cout << lec2 << endl;

	}

	delete std1;
	delete std2;
	delete std3;
	delete teacher1;
	delete teacher2;

	return 0;
}