#include <iostream>

using namespace std;


struct Rectangle
{
	int length;
	int width;
};

enum StudentName
{
	JACK,
	DASH,
	VIOLET,
};

void doSomething(int students_scores[])
{
	cout << students_scores[0] << endl;
	cout << students_scores[1] << endl;
	cout << students_scores[2] << endl;
	cout << &students_scores << endl;
	// size가 main에서의 students_scores는 80인데 doSomething의 students_scores는 4이다 -> 포인터로 넘어왔기 때문에 ( x64설정이면 8bytes이다 )
	cout << sizeof(students_scores) << endl;

}
int main()
{
	int one_student_score;
	int student_scores[5];

	cout << sizeof(one_student_score) << endl;
	cout << sizeof(student_scores) << endl;

	student_scores[0] = 100;

	for (int i = 0; i < 5; i++)
	{
		student_scores[i] = (rand() %101);
		cout << student_scores[i] << endl;
	}
	cout << " ----------------------------- " << endl;
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	cout << sizeof(Rectangle) << endl;

	Rectangle rect_arr[10];
	cout << sizeof(rect_arr) << endl;

	rect_arr[0].length = 10;
	rect_arr[0].width = 1;
	cout << " ----------------------------- " << endl;
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	int my_array[]{ 1,2,3,4,5 };

	cout << my_array[JACK] << endl;
	cout << my_array[DASH] << endl;
	cout << my_array[VIOLET] << endl;

	int students_scores[VIOLET];
	
	students_scores[JACK] = 0;
	students_scores[DASH] = 1;
	
	cout << " ----------------------------- " << endl;
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	const int num_students = 20;
	// cin >> num_students;

	int students_scores1[num_students]{ 1,2,3,4,5 }; // <- num_students는 런타임에 결정되고, students_scores1은 컴파일 시점에 결정됨
	
	cout << &students_scores1 << endl;
	doSomething(students_scores1);
	cout << sizeof(students_scores1) << endl;
	return 0;
}