#pragma once
#include<iostream>
using namespace std;
int MinOrder(int* number, int index1, int index2)
{
	int result = number[index1];
	for (int i = index1 + 1; i <= index2; i++)
	{
		if (result>number[i])
		{
			result = number[i];
		}
	}
	return result;
}
int Min(int* number, int length)
{
	if (number == NULL&&length <= 0)
	{
		return -1;
	}
	int index1 = 0;
	int index2 = length - 1;
	int indexMid = index1;//为了防止旋转0个元素的情况，这样index1对应的元素就是最小元素
	while (number[index1] >= number[index2])
	{
		if (index2 - index1 == 1)
		{
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;
		if (number[index1] == number[index2] && number[indexMid] == number[index1])
		{
			return MinOrder(number, index1, index2);
		}
		if (number[indexMid] >= number[index1])//中间元素位于数组第一部分
		{
			index1 = indexMid;
		}
		else if (number[indexMid] <= number[index2])//中间元素位于数组第二部分
		{
			index2 = indexMid;
		}
	}
	return number[indexMid];
}
void Test()
{
	int arr1[] = { 3, 4, 5, 1, 2 };
	int min1 = Min(arr1, sizeof(arr1) / sizeof(arr1[0]));
	cout << "min1=" << min1 << endl;
	int arr2[] = { 1, 0, 1, 1, 1 };
	int min2 = Min(arr2, sizeof(arr2) / sizeof(arr2[0]));
	cout << "min2=" << min2 << endl;
	int arr5[] = { 1, 1, 1, 0, 1 };
	int min5 = Min(arr5, sizeof(arr5) / sizeof(arr5[0]));
	cout << "min5=" << min5 << endl;
	//int arr3[] = { 7, 3, 4, 1, 6, 5, 9 };
	//int min3 = Min(arr3, sizeof(arr3) / sizeof(arr3[0]));
	//cout << "min3=" << min3 << endl;//输出为7程序正常
	//int arr4[] = { 1, 3, 4, 7, 6, 5, 9 };
	//int min4 = Min(arr4, sizeof(arr4) / sizeof(arr4[0]));
	//cout << "min4=" << min4 << endl;//输出为1程序正常
}
