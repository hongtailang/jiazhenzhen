#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
void AdjustDown(int a[], int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if ((child + 1 < size) && (a[child + 1] > a[child]))
		{
			++child;
		}
		if (a[child]>a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int a[], int n)
{
	//建堆(大堆)
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	//选出最大数据交换到末尾，剩下的数据进行向下调整
	for (int i = 0; i < n; i++)
	{
		swap(a[0], a[n - 1 - i]);
		AdjustDown(a, n - 1 - i, 0);
	}
}
void Test()
{
	int a[10] = { 1, 0, 9, 6, 2, 5, 3, 7, 8, 4 };
	int size = sizeof(a) / sizeof(a[0]);
	HeapSort(a, size);
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
