/*
	Vector
		-> 메모리를 알아서 지워준다
		-> 블럭을 벗어날 때 지움
		-> 자기의 특징을 안다, 길이, 등등
		-> 동적메모리관리에도 유리
*/

#include <iostream>
#include <vector>

using namespace std;


int main()
{
	// array<int,5> array;
	vector<int> arr = { 1,2,3,4,5 };

	arr.resize(10);
	for (auto &itr : arr)
		cout << itr << " ";
	cout << endl;

	cout << arr[1] << endl;
	cout << arr.at(1) << endl;



	return 0;
}