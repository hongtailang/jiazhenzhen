#define _CRT_SECURE_NO_WARNINGS
#include "DList.h"
ostream& operator<<(ostream& os,const DList& d)
{
	Node* cur = d._head;
	while (cur)
	{
		os << cur->_data << "<=>";
		cur = cur->_next;
	}
	os << "over";
	return os;
}
void DList::PushBack(const DataType& d)
{
	Node* newNode = new Node(d);
	if (_head == NULL)
	{
		_head = newNode;
		_tail = _head;
	}
	else
	{
		_tail->_next = newNode;
		newNode->_prev=_tail;
		_tail = newNode;
	}
}
void DList::PushFront(const DataType& d)
{
	Node* newHead = new Node(d);
	if (_head == NULL)
	{
		_head = newHead;
		_tail = _head;
	}
	else
	{
		newHead->_next = _head;
		_head = newHead;
		_head->_prev = NULL;
	}
}
void DList::PopBack()
{
	if (_head == NULL)
	{
		return;
	}
	else if (_head==_tail)
	{
		delete _head;
		_head = NULL;
		_tail = NULL;
	}
	else
	{
		_tail = _tail->_prev;
		delete _tail->_next;
		_tail->_next = NULL;
	}
}
void DList::PopFront()
{
	if (_head == NULL)
	{
		return;
	}
	else if (_head==_tail)
	{
		delete _head;
		_head = NULL;
		_tail = NULL;
	}
	else
	{
		Node* del = _head;
		_head = _head->_next;
		_head->_prev = NULL;
		delete del;
		del = NULL;
	}
}
Node* DList::Find(const DataType& d)
{
	Node* cur = _head;
	while (cur)
	{
		if (cur->_data == d)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
void DList::Insert(Node* pos, const DataType& d)
{
	Node* newNode = new Node(d);
	if (_head == pos)
	{
		newNode->_next = _head;
		_head = newNode;
		_head->_prev = NULL;
	}
	else if (_tail == pos)
	{
		_tail->_next = newNode;
		newNode->_prev = _tail;
		_tail = newNode;
	}
	else
	{
		Node* cur = _head;
		while (cur != pos)
		{
			cur = cur->_next;
		}
		newNode->_next = cur->_next;
		cur->_next = newNode;
		newNode->_prev = cur;
	}
}
void DList::BubbleSort()
{
	Node* cur = _head;
	Node* end = NULL;
	while (cur->_next != end)
	{
		while (cur && (cur->_next != end))
		{
			if (cur->_data > cur->_next->_data)
			{
				DataType tmp = cur->_data;
				cur->_data = cur->_next->_data;
				cur->_next->_data = tmp;
			}
			cur = cur->_next;
		}
		end = cur;
		cur = _head;
	}
}
void DList::Reverse()
{
	Node* newHead = NULL;
	Node* cur = _head;
	Node* prev = NULL;
	if ((cur == NULL) || (cur->_next == NULL))
	{
		return;
	}
	while (cur)
	{
		prev = cur;
		cur = cur->_next;
		prev->_next = newHead;
		newHead = prev;
	}
	_head = newHead;
}
void DList::Remove(const DataType& d)
{
	Node* cur = _head;
	Node* del = NULL;
	Node* prev = NULL;
	while (cur)
	{
		if (cur->_data == d)
		{
			del = cur;
			if (cur == _head)
			{
				_head = _head->_next;
			}
			else
			{
				prev->_next = cur->_next;
			}
			delete del;
			break;
		}
		prev = cur;
		cur = cur->_next;
	}
}

void DList::RemoveAll(const DataType& d)
{
	Node* cur = _head;
	Node* del = NULL;
	Node* prev = NULL;
	while (cur)
	{
		if (cur->_data == d)
		{
			del = cur;
			if (cur == _head)
			{
				_head = _head->_next;
				cur = _head;
			}
			else
			{
				prev->_next = cur->_next;
				cur = prev->_next;

			}
			delete del;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
}
void DList::Erase(Node *pos)
{
	Node* cur = _head;
	Node* del = NULL;
	Node* prev = NULL;
	while (cur)
	{
		if (cur == pos)
		{
			del = cur;
			if (cur == _head)
			{
				_head = _head->_next;
			}
			else
			{
				prev->_next = cur->_next;
			}
			delete del;
			break;
		}
		prev = cur;
		cur = cur->_next;
	}
}
