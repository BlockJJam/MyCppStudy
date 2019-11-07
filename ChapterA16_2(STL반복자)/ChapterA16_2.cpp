/*
	STL - �ݺ���(iterator)
*/

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

using namespace std;

int main()
{
	vector<int> container;

	for (int i = 0; i < 10; i++)
		container.push_back(i);

	//iterator
	vector<int>::const_iterator itr;			// ���� ���
	itr = container.begin();
	while (itr != container.end())
	{
		cout << *itr << " ";
		itr++;
	}
	cout << endl; 

	for (auto & e : container)					// ���� ���
		cout << e << " ";
	cout << endl;

	for (auto itr = container.begin(); itr != container.end(); itr++)
		cout << *itr << " ";
	cout << endl;

	//list		<- vector�� ���� �������� ���� �ٸ�
	/*list<int> container1;
	for (int i = 0; i < 10; i++)
		container1.push_back(i);

	for (auto itr = container1.begin(); itr != container1.end(); itr++)
		cout << *itr << " ";
	cout << endl;*/

	//set
	/*set<int> container1;
	for (int i = 0; i < 10; i++)
		container1.insert(i);

	for (auto itr = container1.begin(); itr != container1.end(); itr++)
		cout << *itr << " ";
	cout << endl;*/

	map<int, char> container1;
	for (int i = 0; i < 10; i++)
		container1.insert(make_pair(i, char(i + 65)));

	for (auto itr = container1.begin(); itr != container1.end(); itr++)
		cout << itr->first << " " << itr->second << endl;
	cout << endl;

	return 0;
}