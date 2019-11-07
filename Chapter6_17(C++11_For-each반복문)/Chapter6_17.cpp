/*
	For-Each
		-> for( : ) ����
		-> �����迭������ ��� �Ұ���

*/

#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	/*int fibonacci[] = { 0,1,1,2,3,5,8,13,21,34,55,89 };*/
	vector<int> fibonacci = { 0,1,1,2,3,5,8,13,21,34,55,89 };


	// change array values
	for (auto& number : fibonacci)				// ���������� �����ͷ� �޾ƾ� fibonacci ����� �ٲ�
	{
		//number = 10;
	}


	// output
	for (const auto &number : fibonacci)			// �б⸸ �� ���̱� ������ fibonacci ���� �ٲ��� �ʰڴ�
	{
		cout << number << " ";
	}
	cout << endl;

	// max number
	int max_number = numeric_limits<int>::lowest();
	cout << max_number << endl;

	for (const auto& n : fibonacci)
	{
		max_number = max(max_number, n);
	}
	cout << max_number << endl;

	// ���� �迭���� for-each �Ұ��� , �� �������� -> vector ( ������ )

	return 0;
}