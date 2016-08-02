#pragma once
#include<iostream>
using namespace std;
void ReorderOddEvev1(int *pData, int length)
{
	if (pData == NULL || length <= 0)
	{
		return;
	}
	int* pStart = pData;
	int* pEnd = pData + length - 1;
	while (pStart < pEnd)
	{
		while (pStart < pEnd&&(*pStart & 0x1) != 0)
		{
			pStart++;
		}
		while (pStart < pEnd&&(*pEnd & 0x1) == 0)
		{
			pEnd--;
		}
		if (pStart < pEnd)
		{
			int tmp = *pStart;
			*pStart = *pEnd;
			*pEnd = tmp;
		}
	}
}
void Reorder(int *pData, int length, bool(*func) (int))//用函数指针实现通用的逻辑框架
{
	if (pData == NULL || length <= 0)
	{
		return;
	}
	int* pStart = pData;
	int* pEnd = pData + length - 1;
	while (pStart < pEnd)
	{
		while (pStart < pEnd&&!func(*pStart))
		{
			pStart++;
		}
		while (pStart < pEnd&&func(*pEnd))
		{
			pEnd--;
		}
		if (pStart < pEnd)
		{
			int tmp = *pStart;
			*pStart = *pEnd;
			*pEnd = tmp;
		}
	}
}
bool isEven(int n)
{
	return (n & 1) == 0;//返回1为偶数，返回0为奇数
}
void ReorderOddEven2(int *pData, int length)
{
	Reorder(pData, length, isEven);
}
void Test1()//功能测试
{
	int a1[] = { 1, 0, 2, 3, 5, 4, 6, 9, 7, 8 };
	int len1 = sizeof(a1) / sizeof(a1[0]);
	ReorderOddEven2(a1, len1);
	for (int i = 0; i < len1; i++)
	{
		cout << a1[i] << " ";
	}
	cout << endl;

	int a2[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int len2 = sizeof(a2) / sizeof(a2[0]);
	ReorderOddEven2(a2, len2);
	for (int i = 0; i < len2; i++)
	{
		cout << a2[i] << " ";
	}
	cout << endl;

	int a3[] = { 2, 4, 6, 8, 0, 1, 3, 5, 7, 9 };
	int len3 = sizeof(a3) / sizeof(a3[0]);
	ReorderOddEven2(a3, len3);
	for (int i = 0; i < len3; i++)
	{
		cout << a3[i] << " ";
	}
	cout << endl;
}
void Test2()//特殊输入测试
{
	int a4[] = { 1 };
	int len4 = sizeof(a4) / sizeof(a4[0]);
	ReorderOddEven2(a4, len4);
	for (int i = 0; i < len4; i++)
	{
		cout << a4[i] << " ";
	}
	cout << endl;
	ReorderOddEven2(NULL, 0);
	cout << endl;
}