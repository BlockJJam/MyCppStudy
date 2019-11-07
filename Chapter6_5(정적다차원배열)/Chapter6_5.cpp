#include <iostream>

using namespace std;

int main()
{
	const int num_rows = 3;
	const int num_columns = 5;

	// array initialization 1
	int array1[num_rows][num_columns] =
	{
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15}
	};
	// array initialization 2
	int array2[num_rows][num_columns] =
	{
		{1,2,},							// 1 2 0 0 0 
		{6,7,},							// 6,7,0,0,0
		{11,12,}						// 11,12,0,0,0
	};

	// array initialization 3
	int array3[num_rows][num_columns] = { 0, };


	for (int row = 0; row < num_rows; ++row)
	{
		for (int col = 0; col < num_columns; ++col)
		{
			//cout << '[' << row << ']' << '[' << col << ']' << '\t';
			cout << "a"<<array1[row][col] << '\t';
			cout << "b"<<array2[row][col] << '\t';
			cout << "c"<<array3[row][col] << '\t';
		}
		cout << endl;
	}
	cout << endl;
	



	
	return 0;
}