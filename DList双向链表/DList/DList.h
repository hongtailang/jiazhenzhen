#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
using namespace std;
typedef int DataType;
struct Node
{
	Node(const DataType& d)
	:_data(d)
	, _prev(NULL)
	, _next(NULL)
	{}
	Node* _next;
	Node* _prev;
	DataType _data;
};
class DList
{
	friend ostream& operator<<(ostream& os, const DList& d);
public:
	DList()
		:_head(NULL)
		, _tail(NULL)
	{}
	~DList()
	{
		Node* cur = _head;
		while (cur)
		{
			Node* del = cur;
			cur = cur->_next;
			delete del;
		}
	}
public:
	void PushBack(const DataType& d);
	void PushFront(const DataType& d);
	void PopBack();
	void PopFront();
	Node* Find(const DataType& d);
	void Insert(Node* pos, const DataType& d);
	void BubbleSort();
	void Reverse();
	void Remove(const DataType& d);
	void RemoveAll(const DataType& d);
	void Erase(Node *pos);
private:
	Node* _head;
	Node* _tail;
};
