#define _CRT_SECURE_NO_WARNING
#pragma once
#include<iostream>
#include<assert.h>
#include<vector>
using namespace std;
template <typename T>
class Heap
{
public:
	Heap()
	{}
	Heap(const T* a, size_t size)
	{
		assert(a);
		for (size_t i = 0; i < size; i++)
		{
			_a.push_back(a[i]);
		}
		//建堆
		for (int i = (_a.size() - 2) / 2; i >= 0; i--)
		{
			_AdjustDown(i);
		}
	}
	void Push(const T& x)
	{
		_a.push_back(x);
		_AdjustUp(_a.size() - 1);
	}
	void Pop()
	{
		assert(!_a.empty());
		swap(_a[0], _a[_a.size() - 1]);
		_a.pop_back();
		_AdjustDown(0);
	}
protected:
	void _AdjustDown(size_t parent)
	{
		size_t child = parent * 2 + 1;
		while (child < _a.size())
		{
			if ((child + 1 < _a.size())&&(_a[child + 1]>_a[child]))
			{
				++child;
			}
			if (_a[child] > _a[parent])
			{
				swap(_a[child], _a[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}
	void _AdjustUp(size_t child)
	{
		size_t parent = (child-1) / 2;
		while ((parent >= 0) && (child > 0))
		{
			if (_a[child] > _a[parent])
			{
				swap(_a[child], _a[parent]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}
protected:
	vector<T> _a;//用顺序表完成
};
void Test()
{
	int array1[10] = { 10, 16, 18, 12, 11, 13, 15, 17, 14, 19 };
	Heap<int> h1(array1, 10);
	h1.Push(20);
	h1.Pop();
}