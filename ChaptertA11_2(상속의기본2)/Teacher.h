#pragma once

#include "Person.h"

class Teacher : public Person
{
private:

	//TODO : more members like home address, salary, age, evaluation, etc.

public:
	Teacher(const std::string & name_in = "No Name")
		:Person(name_in)
	{}

	void teach()
	{
		cout << getName() << " is teaching " << endl;
	}
	
	friend std::ostream & operator << (std::ostream & out, const Teacher & teacher)
	{
		out << teacher.getName();
		return out;
	}
};