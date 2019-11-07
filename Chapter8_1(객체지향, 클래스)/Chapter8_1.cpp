/*
	단순한 기능만 쓸 때는 Struct (데이터만 묶는데)
	기능을 묶을 때는 Class

	Object : 기능들을 개념적으로 생각하는 것을 객체
	class : Object를 코드화 한 것
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Friend
{
public:				// access specifier( public, private, protected )
	string _name;
	string _address;
	int _age;
	double _height;
	double _weight;

	void print()
	{
		cout << _name << " " << _address << " " << _age << _height << " " << _weight;
	}
};

int main()
{
	
	Friend fr{ "jack", "uptown ", 2,30,10 };		// instanciation 객체를 메모리화, fr <- 클래스의 instance

	fr.print();

	vector<Friend> my_friends;
	my_friends.resize(2);

	my_friends[0].print();
	my_friends[1].print();
	my_friends[2].print();

	for (auto &ele : my_friends)
		ele.print();

	return 0;
}
