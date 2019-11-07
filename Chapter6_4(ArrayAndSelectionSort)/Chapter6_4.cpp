#include <iostream>

using namespace std;

void printArray(int array[], int length)
{
	for (int index = 0; index < length; ++index)
	{
		cout << array[index] << " ";
	}
	cout << endl;
}

int main()
{
	/* 
		3,5,2,1,4 선택정렬
	*/

	const int length = 5;
	int array[] = { 3,5,2,1,4 };

	printArray(array, length);
	int select_value = array[0];
	for (int startIndex = 0; startIndex < length - 1; ++startIndex)
	{
		int smallestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
		{
			if (array[smallestIndex] > array[currentIndex])
				smallestIndex = currentIndex;
		}
		select_value = array[smallestIndex];
		array[smallestIndex]= array[startIndex];
		array[startIndex] = select_value;
	}
	printArray(array, length);

	/* Bubble sort */

	return 0;
}