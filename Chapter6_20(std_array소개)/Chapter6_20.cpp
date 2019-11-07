#include <iostream>
#include <array>

using namespace std;

void printLength(array<int, 5 > &my_arr)			// �����ؾ� �� �� : �̰͵� ���簳�� arr�� ũ�� �������� ����
{
	cout << my_arr.size() << endl;
}

int main()
{
	//int array[5] = { 1,2,3,4,5 };
	array<int, 5> my_arr = { 1,21,3,40,5 };

	cout << my_arr.at(1) << endl;	// at(10) = [10] ������ ����ó���� �߰���, 
	
	printLength(my_arr);

	for (auto &element : my_arr)
		cout << element << " ";
	cout << endl;

	sort(my_arr.rbegin(), my_arr.rend());

	for (auto &element : my_arr)
		cout << element << " ";
	cout << endl;

	return 0;
}