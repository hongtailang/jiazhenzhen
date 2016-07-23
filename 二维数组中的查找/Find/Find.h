#pragma once
#include<iostream>
using namespace std;
bool Find(int* matrix, int rows, int columns, int number)
{
	bool found = false;
	int row = 0;
	int column = columns - 1;
	if (matrix != NULL&&rows > 0 && columns > 0)
	{
		int row = 0;
		int column = columns - 1;
		while (row >= 0 && column > 0)
		{
			if (matrix[row*columns + column] == number)
			{
				found = true;
				return found;
			}
			else if (matrix[row*columns + column] > number)
			{
				column--;
			}
			else
			{
				row++;
			}
		}
	}
	return found;
}
void TestFind()
{
	int arr[] = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15};
	bool ret1 = Find(arr, 4, 4, 7);
	bool ret2 = Find(arr, 4, 4, 20);
	cout << "ret1:" << " " << ret1 << endl;
	cout << "ret2:" << " " << ret2 << endl;
}