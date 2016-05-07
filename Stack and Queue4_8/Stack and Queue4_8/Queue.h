#define _CRT_SECURE_NO_WARNING
#pragma once
#include<iostream>
using namespace std;
template<typename T>
struct Node
{
	Node(const T& x)
			:_data(x)
			, _next(NULL)
	{}
	T _data;
	Node<T>* _next;
};
template<typename T>
class Queue
{
public:
	Queue()
		:_head(NULL)
		, _tail(NULL)
	{}
	~Queue()
	{
		if (_head == NULL)
		{
			return;
		}	
		Node<T>* cur = _head;
		while (cur->_next != NULL)
		{
			Node<T>* del = cur;
			cur = cur->_next;
			delete del;
		}
		delete cur;
		_head = NULL;
		_tail = NULL;
	}
	Queue(const Queue& q)
		:_head(NULL)
		, _tail(NULL)
	{
		Node<T>* cur = q._head;
		while (cur)
		{
			Push(cur->_data);
			cur = cur->_next;
		}
	}
	Queue& operator=(Queue& q)
	{
		swap(_head, q._head);
		swap(_tail, q._tail);
		return *this;
	}
public:
	void Push(const T& t)
	{
		Node<T>* newNode = new Node<T>(t);
		if (_head == NULL)//нч╫з╣Ц
		{
			_head = newNode;
			_tail = _head;
		}
		else
		{
			_tail->_next = newNode;
			_tail = newNode;
			_tail->_next = NULL;
		}
	}
	void Pop()
	{
		if (_head == NULL)
		{
			return;
		}
		else
		{
			Node<T>* del = _head;
			_head = _head->_next;
			delete del;
		}
	}
	T& Front()
	{
		return _head->_data;
	}
	T& Back()
	{
		return _tail->_data;
	}
	bool Empty()
	{
		if (_head == NULL)
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
		if (_head != NULL)
		{
			size_t size = 0;
			Node<T>* cur = _head;
			while (cur)
			{
				size++;
				cur = cur->_next;
			}
			return size;
		}
		return 0;
	}
	void PrintQueue()
	{
		if (_head != NULL)
		{
			Node<T>* cur = _head;
			while (cur)
			{
				cout << cur->_data << "--";
				cur = cur->_next;
			}
		}
		cout << "over" << endl;
	}
protected:
	Node<T>* _head;
	Node<T>* _tail;
};

void TestQueue1()
{
	Queue<int> q1;
	Queue<int> q2(q1);
	Queue<int> q3;
	q1 = q3;
}
void TestQueue2()
{
	Queue<int> q1;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q1.Push(4);
	q1.PrintQueue();
	int ret1 = q1.Front();
	cout << "ret1:" << ret1 << endl;
	int ret2=q1.Back();
	cout << "ret2:" << ret2 << endl;
	bool ret3=q1.Empty();
	cout << "ret3:" << ret3 << endl;
	size_t ret4=q1.Size();
	cout << "ret4:" << ret4 << endl;
	q1.Pop();
	q1.PrintQueue();
	q1.Pop();
	q1.PrintQueue();
	q1.Pop();
	q1.PrintQueue();
	q1.Pop();
	q1.PrintQueue();
	q1.Pop();
	q1.PrintQueue();
}
