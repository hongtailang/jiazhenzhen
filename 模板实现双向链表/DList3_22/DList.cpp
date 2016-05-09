#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNING
#include<iostream>
using namespace std;
template<typename T>
struct Node
{
	Node(const T& d)
	:_next(NULL)
	, _prev(NULL)
	, _data(d)
	{}
	Node<T>* _next;
	Node<T>* _prev;
	T _data;
};
template<typename T>
class DList
{
public:
	DList();
	~DList();
	DList(const DList& d);
	DList& operator=(const DList& d);
public:
	void Print()const;
	void PushBack(const T& t);
	void PopBack();
	void PushFront(const T& t);
	void PopFront();
	Node<T>* Find(const T& t);
	void Insert(Node<T>* pos, const T& t);
	void Reverse();
	void Sort();
private:
	Node<T>* _head;
	Node<T>* _tail;
};
template<typename T>
DList<T>::DList()
:_head(NULL)
, _tail(NULL)
{}
template<typename T>
DList<T>::~DList()
{
	Node<T>* cur = _head;
	while (cur != NULL)
	{
		Node<T>* del = cur;
		cur = cur->_next;
		delete del;
	}
}
template<typename T>
DList<T>::DList(const DList<T>& d)
{

}
template<typename T>
DList<T>& DList<T>::operator=(const DList<T>& d)
{

}
template<typename T>
void DList<T>::Print()const
{
	Node<T>* cur = _head;
	while (cur != NULL)
	{
		cout << cur->_data << "->";
		cur = cur->_next;
	}
	cout << "over" << endl;
}
template<typename T>
void DList<T>::PushBack(const T& t)
{
	Node<T>* newNode = new Node<T>(t);
	if (_head == NULL)
	{
		_head = newNode;
		_tail = _head;
	}
	else
	{
		_tail->_next = newNode;
		newNode->_prev = _tail;
		_tail = newNode;
		_tail->_next = NULL;
	}
}
template<typename T>
void DList<T>::PopBack()
{
	if (_head != NULL)
	{
		if (_head == _tail)
		{
			_head = NULL;
			_tail = NULL;
			return;
		}
		_tail = _tail->_prev;
		_tail->_next = NULL;
	}
}
template<typename T>
void DList<T>::PushFront(const T& t)
{
	Node<T>* newHead = new Node<T>(t);
	if (_head == NULL)
	{
		_head = newHead;
		_tail = _head;
	}
	else
	{
		_head->_prev = newHead;
		newHead->_next = _head;
		_head = newHead;
		_head->_prev = NULL;
	}
}
template<typename T>
void DList<T>::PopFront()
{
	if (_head != NULL)
	{
		if (_head == _tail)
		{
			_head = NULL;
			_tail = NULL;
			return;
		}
		_head = _head->_next;
		_head->_prev = NULL;
	}
}
template<typename T>
Node<T>* DList<T>::Find(const T& t)
{
	if (_head != NULL)
	{
		Node<T>* cur = _head;
		while (cur)
		{
			if (cur->_data == t)
				return cur;
			else
				cur = cur->_next;
		}
	}
	return NULL;
}
template<typename T>
void DList<T>::Insert(Node<T>* pos, const T& t)
{
	Node<T>* newNode = new Node<T>(t);
	if (_head != NULL)
	{
		if (_head == pos)
		{
			newNode->_next = _head;
			_head = newNode;
			_head->_prev = NULL;
			_head->_prev = NULL;
		}
		else if (_tail == pos)
		{
			_tail->_next = newNode;
			newNode->_prev = _tail;
			_tail = newNode;
			_tail->_next = NULL;
		}
		else
		{
			Node<T>* cur = _head;
			while (cur != pos)
			{
				cur = cur->_next;
			}
			newNode->_next = cur->_next;
			cur->_next = newNode;
			newNode->_prev = cur;
		}
	}
}
template<typename T>
void DList<T>::Reverse()
{
	Node<T>* newHead = NULL;
	Node<T>* cur = _head;
	Node<T>* prev = NULL;
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
template<typename T>
void DList<T>::Sort()
{
	Node<T>* cur = _head;
	Node<T>* end = NULL;
	while (cur->_next != end)
	{
		while (cur && (cur->_next != end))
		{
			if (cur->_data > cur->_next->_data)
			{
				T tmp = cur->_data;
				cur->_data = cur->_next->_data;
				cur->_next->_data = tmp;
			}
			cur = cur->_next;
		}
		end = cur;
		cur = _head;
	}
}
void test1()
{
	DList<int> d1;
	d1.PushBack(1);
	d1.PushBack(2);
	d1.PushBack(3);
	d1.PushBack(4);
	d1.Print();
	d1.PopBack();
	d1.Print();
	d1.PopBack();
	d1.Print();
	d1.PopBack();
	d1.Print();
	d1.PopBack();
	d1.Print();
	d1.PopBack();
	d1.Print();
	d1.PopBack();
	d1.Print();
}
void test2()
{
	DList<int> d1;
	d1.PushFront(1);
	d1.PushFront(2);
	d1.PushFront(3);
	d1.PushFront(4);
	d1.Print();
	d1.PopFront();
	d1.Print();
	d1.PopFront();
	d1.Print();
	d1.PopFront();
	d1.Print();
	d1.PopFront();
	d1.Print();
	d1.PopFront();
	d1.Print();
	d1.PopFront();
	d1.Print();
}
void test3()
{
	DList<int> d1;
	d1.PushBack(1);
	d1.PushBack(2);
	d1.PushBack(3);
	d1.PushBack(4);
	d1.Print();
	Node<int>* pos = d1.Find(2);
	cout << pos << endl;
	d1.Insert(pos, 5);
	d1.Print();
}
void test4()
{
	DList<int> d1;
	d1.PushFront(1);
	d1.PushFront(3);
	d1.PushFront(2);
	d1.PushFront(5);
	d1.PushFront(0);
	d1.PushFront(9);
	d1.PushFront(8);
	d1.Print();
	d1.Reverse();
	d1.Print();
	d1.Sort();
	d1.Print();
}
int main()
{
	test4();
	system("pause");
	return 0;
}