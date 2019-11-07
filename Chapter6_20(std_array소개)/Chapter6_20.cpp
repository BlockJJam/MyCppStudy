#include <iostream>
#include <array>

using namespace std;

void printLength(array<int, 5 > &my_arr)			// 주의해야 할 점 : 이것도 복사개념 arr이 크면 성능저하 심함
{
	cout << my_arr.size() << endl;
}

int main()
{
	//int array[5] = { 1,2,3,4,5 };
	array<int, 5> my_arr = { 1,21,3,40,5 };

	cout << my_arr.at(1) << endl;	// at(10) = [10] 이지만 예외처리가 추가됨, 
	
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