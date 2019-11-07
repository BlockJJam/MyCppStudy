/*
	이중포인터와 동적 다차원 배열
	(차원 행렬 구할 때 많이 사용)
*/

#include <iostream>

using namespace std;

int main()
{
	int *ptr = nullptr;
	int **ptrptr = nullptr;

	int value = 5;
	ptr = &value;
	ptrptr = &ptr;

	cout << ptr << " " << *ptr << " " << &ptr << endl;
	cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl;
	cout << **ptrptr << endl;
	cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << endl;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

	const int row = 3;
	const int col = 5;
	
	// 정적
	const int s2da[row][col]=
	{
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15}
	};

	// 이중포인터를 사용하지 않고 동적 다차원 배열( 1차원 array이지만 2차원 처럼 사용하는 법)
	
	int *matrix = new int[row*col];
	
	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			matrix[c+col*r] = s2da[r][c];

	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			cout << matrix[c+ col *r] << " ";
		}
		cout << endl;
	}

	delete[] matrix;
	/*
														  -- 이중 포인터로 동적 배열 방법 --
	// 동적배열
	int *r1 = new int[col] { 1,2,3,4,5 };
	int *r2 = new int[col] { 6,7,8,9,10 };
	int *r3 = new int[col] { 11,12,13,14,15 };

	// 이중포인터와 동적다차원배열
	int **rows = new int*[row]{ r1,r2,r3 };


	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			cout << rows[r][c] << " ";
		}
		cout << endl;
	}
	// 이중 포인터 다른방식
	int **matrix = new int*[row];

	for (int r = 0; r < row; r++)
		matrix[r] = new int[col];

	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			matrix[r][c] = s2da[r][c];

	for (int r = 0; r < row; r++)
	{
		for (int c = 0; c < col; c++)
		{
			cout << matrix[r][c] << " ";
		}
		cout << endl;
	}

	//delete
	for (int r = 0; r < row; r++)
		delete[] matrix[r];

	delete[] matrix;

	*/
	return 0;
}