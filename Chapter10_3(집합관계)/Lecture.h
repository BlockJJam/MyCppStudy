#pragma once

#include <vector>
#include "Student.h"
#include "Teacher.h"

class Lecture
{
private:
	std::string _name;

	Teacher * teacher;
	std::vector<Student*> students;		//comsition relation

public:
	Lecture(const std::string & name_in)
		: _name(name_in)
	{}

	~Lecture()
	{
		// do Not delete teacher
		// do Not delete sutdents
	}

	void assignTeacher(Teacher * const teacher_input)
	{
		teacher = teacher_input;
	}

	void registerStudent(Student * const  student_input)
	{
		students.push_back(student_input);
	}

	void study()
	{
		std::cout << _name << " Study " << std::endl << std::endl;

		for (auto & ele : students) // Note : "auto ele " doesn't work &가 없으면 ele.getIntel() + 1 을 안한다
			ele->setIntel(ele->getIntel() + 1);
	}

	friend std::ostream &  operator << (std::ostream & out, const Lecture & lecture)
	{
		out << "Lecture name : " << lecture._name << std::endl;

		out << lecture.teacher << std::endl;
		for (auto ele : lecture.students)
			out << *ele << std::endl;

		return out;
	}
};