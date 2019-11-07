/*
	�ܼ��� ��ɸ� �� ���� Struct (�����͸� ���µ�)
	����� ���� ���� Class

	Object : ��ɵ��� ���������� �����ϴ� ���� ��ü
	class : Object�� �ڵ�ȭ �� ��
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
	
	Friend fr{ "jack", "uptown ", 2,30,10 };		// instanciation ��ü�� �޸�ȭ, fr <- Ŭ������ instance

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
