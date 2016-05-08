#define _CRT_SECURE_NO_WARNING
#pragma once
#include<iostream>
using namespace std;
template<typename T>
class Stack
{
public:
	Stack()
		:_a(0)
		, _top(0)
		, _capacity(0)
	{
		CheckCapacity();
	}
	~Stack()
	{
		if (_a != NULL)
		{
			delete[] _a;
		}
	}
	Stack(const Stack& s)
		: _a(new T[s._top])
		, _top(s._top)
		, _capacity(s._capacity)
	{
		for (size_t i = 0; i < _top; i++)
		{
			_a[i] = s._a[i];
		}
	}
	Stack& operator=(Stack& s)
	{
		//传统写法
		//if (this != &s)
		//{
		//	_a = new T[s._top];
		//	delete[] _a;
		//	_top = s._top;
		//	_capacity = s._capacity;
		//	for (size_t i = 0; i < _top; i++)
		//	{
		//		_a[i] = s._a[i];
		//	}
		//}

		//现代写法
		swap(_a, s._a);
		_top = s._top;
		_capacity = s._capacity;
		return *this;
	}
public:
	void CheckCapacity()
	{
		if (_top == _capacity)
		{
			_capacity = _capacity * 2 + 5;
			T* tmp = new T[_capacity];
			for (size_t i = 0; i < _top; i++)
			{
				tmp[i] = _a[i];
			}
			delete[] _a;
			_a = tmp;
		}
	}
	void PrintStack()
	{
		if (_top != 0)
		{
			for (size_t i = 0; i < _top; i++)
			{
				cout << _a[i] << "--";
			}
		}
		cout <<"over"<<endl;
	}
public:
	bool Empty()
	{
		if (_top == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	size_t Size()
	{
		return _top;
	}
	T& Top()
	{
		return _a[_top-1];
	}
	void Push(const T& t)
	{
		CheckCapacity();
		_a[_top] = t;
		_top++;
	}
	void Pop()
	{
		if (_top != 0)
		{
			_top--;
		}
	}
protected:
	T* _a;
	size_t _top;
	size_t _capacity;
};

void TestStack1()
{
	Stack<int> s1;
	Stack<int> s2;
	Stack<int> s3;
	s3 = s2;
}
void TestStack2()
{
	Stack<int> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.PrintStack();
	bool ret1 = s1.Empty();
	cout << "ret1:" << ret1 << endl;
	size_t ret2 = s1.Size();
	cout << "ret2:" << ret2<< endl;
	int ret = s1.Top();
	cout << "ret:" << ret << endl;
	s1.Pop();
	s1.PrintStack();
	s1.Pop();
	s1.PrintStack();
	s1.Pop();
	s1.PrintStack();
	s1.Pop();
	s1.PrintStack();
	s1.Pop();
}

