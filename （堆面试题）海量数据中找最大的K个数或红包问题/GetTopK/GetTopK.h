#define _CRT_SECURE_NO_WARNING
#pragma once
#include<iostream>
#include<time.h>
#include<assert.h>
using namespace std;
const int N = 1000;
const int K = 100;
void AdjustDown(int topK[], int size, int parent)
{
	assert(topK);
	int child = parent * 2 + 1;
	while (child < size)
	{
		if ((child + 1 < size) && (topK[child + 1] < topK[child]))
		{
			++child;
		}
		if (topK[child] < topK[parent])
		{
			swap(topK[child], topK[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void GetTopK(int a[], int topK[])
{
	assert(a);
	for (int i = 0; i < K; i++)
	{
		topK[i] = a[i];
	}
	for (int i = (K - 2) / 2; i >= 0; i--)
	{
		AdjustDown(topK,K,i);
	}
	for (int i = K - 1; i < N; i++)
	{
		if (a[i]>topK[0])
		{
			topK[0] = a[i];
			AdjustDown(topK, K, 0);
		}
		else
		{
			break;
		}
	}
}
void Test()
{
	int a1[N];
	int a2[K];
	srand((int)time(0));
	for (int i = 0; i < N; i++)
	{
		a1[i] = rand()%10000;
	}
	GetTopK(a1, a2);
	for (int i = 0; i < K; i++)
	{
		a2[i] = a2[i] + 1000000;
		cout << a2[i] << " ";
	}
	cout << endl;
}